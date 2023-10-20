import * as vscode from 'vscode';

class MyState {
	static rexlangH: string;
	static rexlangDefinitionsH: string;
	public constructor() { }
}

function mergeSettings(settingString: string, settingValue: string, configTarget: vscode.ConfigurationTarget) {
	const config = vscode.workspace.getConfiguration();
	if (config.has(settingString)) {
		const x = config.get(settingString) as Array<string>;

		// remove setings from old versions
		const y: Array<string> = [];
		x.forEach((str) => {
			if (!str.includes("jangebhart.rexlang")) {
				y.push(str);
			}
		});

		// merge settings
		if (!y.includes(settingValue)) {
			y.push(settingValue);
		}
		config.update(settingString, y, configTarget);
	}
}

function removeSettings(settingString: string, settingValue: string, configTarget: vscode.ConfigurationTarget) {
	const config = vscode.workspace.getConfiguration();
	if (config.has(settingString)) {
		const x = config.get(settingString) as Array<string>;
		if (x.includes(settingValue)) {
			x.splice(x.indexOf(settingValue), 1);
		}
		config.update(settingString, x, configTarget);
	}
}

export function activate(context: vscode.ExtensionContext) {
	// Initialize the MyState class.
	const s = new MyState();

	// Set the rexlangh and rexlangdefinitionsh paths.
	MyState.rexlangH = vscode.Uri.joinPath(context.extensionUri, 'rexlang.h').fsPath;
	MyState.rexlangDefinitionsH = vscode.Uri.joinPath(context.extensionUri, 'rexlang_definitions.h').fsPath;

	// Log a message to the console.
	console.log('Congratulations, your extension "rexlang" is now active!');

	// Merge the rexlangh path into the C_Cpp.default.forcedInclude setting.
	mergeSettings('C_Cpp.default.forcedInclude', MyState.rexlangH , vscode.ConfigurationTarget.Global);

	// Merge the rexlangdefinitionsh path into the C_Cpp.codeAnalysis.clangTidy.args setting.
	mergeSettings('C_Cpp.codeAnalysis.clangTidy.args', '-header-filter "' + MyState.rexlangDefinitionsH + '"' , vscode.ConfigurationTarget.Global);

	// Show an information message to the user.
	vscode.window.showInformationMessage('Rexlang support was added! To activate in workspace use command Rexlang: Activate in workspace.');

	// Register the rexlang.activate command.
	context.subscriptions.push(
		vscode.commands.registerCommand('rexlang.activate', () => {
			mergeSettings('C_Cpp.default.defines', "REXLANG", vscode.ConfigurationTarget.Workspace);
			vscode.window.showInformationMessage('Rexlang support was removed!');
		})
	);

	// Register the rexlang.deactivate command.
	context.subscriptions.push(
		vscode.commands.registerCommand('rexlang.deactivate', () => {
			removeSettings('C_Cpp.default.defines', "REXLANG", vscode.ConfigurationTarget.Workspace);
		})
	);
}

export function deactivate() {
	removeSettings('C_Cpp.default.forcedInclude', MyState.rexlangH , vscode.ConfigurationTarget.Global);
	removeSettings('C_Cpp.codeAnalysis.clangTidy.args', '-header-filter "' + MyState.rexlangDefinitionsH + '"' , vscode.ConfigurationTarget.Global);
	vscode.window.showInformationMessage('Rexlang support was deactivated!');
}
