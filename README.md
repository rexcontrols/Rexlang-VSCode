# Rexlang
This extension adds support for Rexlang syntax.

## Rexlang Documentation
https://www.rexygen.com/doc/ENGLISH/MANUALS/BRef/REXLANG.html

## Rexygen Documentation
https://www.rexygen.com/

## Features
The extension provides the following features:
* Syntax highlighting for Rexlang files
* Auto-completion for Rexlang keywords and functions
* Basic Rexlang documentation
* Linting for Rexlang code

## Installation
To install the extension, open the Extensions view in Visual Studio Code and search for "Rexlang". Click the Install button to install the extension.

## Usage
> **To use the extension, you must open a folder or parent folder in Visual Studio Code that contains Rexlang files**.

> **The extension will not automatically provide syntax highlighting, auto-completion, and linting for your code. To enable these features, you must use the following commands:**

Pres `F1` and then type:

> * "Rexlang: Activate in workspace" `rexlang.activate`: Activates the extension in the current workspace.
> * "Rexlang: Deactivate in workspace" `rexlang.deactivate`: Deactivates the extension in the current workspace.

### Manual activation for folder

To manually activate the Rexlang extension in a folder, add a `.vscode/settings.json` file with the following content:

```json
{
    "C_Cpp.default.defines": [
        "REXLANG"
    ]
}
```

This will enable the extension in the current folder and all of its subfolders. If you use `rexlang.activate` command it create same `.vscode/settings.json` file.

## REXYGEN Studio support
REXYGEN Studio support will be added in future release.

## Troubleshooting
If you are having problems with the extension, please report them on the GitHub repository.