/*
TODO
System functions (mino "Trace")
*/

#define output(x)

#define parameter(x)

#define input(x)

#define string char*
#define bool int

#define true 1
#define false 0

// the init procedure is executed once when the REXLANG function block initializes
long init(void);

// the exit procedure is executed once when the task is correctly terminated
//  (system shutdown, downloading new control algorithm, etc.)
long exit(void);

// the main procedure is executed once in each sampling period
long main(void);

// executed on parameters change in REXYGEN
long parchange(void);

// Displays the id value and the val value. The function is intended for debugging. The id is a user-defined constant (from 0 to 9999) for easy identification of the displayed message. The val can be of any data type including text string. The output can be found in the system log of REXYGEN
void Trace(int id, string val);

/*__________________________________Vector functions______________________________________________*/

// double max([n,]val1,…,valn)
// Returns the maximum value. The first parameter defining the number of items is optional.
double max(double val1, double val2, ...);

// Returns the value of maximal item in the vec vector.
double max(int n, int *vec);

// Returns the value of minimal item in the vec vector.
double min(int n, int *vec);

// Returns the minimum value. The first parameter defining the number of items is optional.
// double min[n,]val1,…,valn)
double min(double val1, double val2, ...);

// Evaluates the polynomial y=an∗xn+…+a1∗x+a0. The first parameter defining the number of items is optional.
// double poly([n,]x,an,…,a1,a0)
double poly(double x, double an, double an__1, double an__2, ...);

// Evaluates the polynomial y=vec[n]∗xn+…+vec[1]∗x+vec[0].
double poly(int n, double x, int *vec);

// Evaluates the scalar product y=vec1[0]∗vec2[0]+…+vec1[n-1]∗vec2[n-1].
double scal(int n, int *vec1, int *vec2);

// Evaluates the scalar product y=vec1[0]∗vec2[0]+vec1[skip1]∗vec2[skip2]+…+vec1[(n-1)*skip1]∗vec2[(n-1)*skip2].
// This is well suited for multiplication of matrices, which are stored as vectors (line by line or column by column).
double scal(int n, int *vec1, int *vec2, int skip1, int skip2);

// Evaluates the convolutory product y=vec1[0]∗vec2[n-1]+vec1[1]∗vec2[n-1]+…+vec1[n-1]∗vec2[0].
double conv(int n, int *vec1, int *vec2);

// Sums the items in a vector, i.e. y=vec[0]+vec[1]+…+vec[n-1].
double sum(int n, int *vec);

// Sums the items, i.e. y=val1+val2+…+valn. The first parameter defining the number of items is optional.
// double sum([n,]val1,…,valn)
double sum(double val1, double val2, ...);

// Returns an array/vector with the given values. The first parameter defining the number of items is optional. The type of the returned value is chosen automatically to fit the type of parameters (all must be of the same type).
// int *array([n,]an-1,…,a1,a0)
int *array(double an__1, double an__2, ...);

// Returns a subarray/subvector of the vec array, starting at the idx index. The type of the returned value is chosen automatically according to the vec array.
int *subarray(int idx, int *vec);

// Copies count items of the vecSource array, starting at idxSource index, to the vecTarget array, starting at idxTarget index. Both arrays must be of the same type.
void copyarray(int count, int *vecSource, int idxSource, int *vecTarget, int idxTarget);

// Copies value to count items of the vector array (always starting from index 0).
void fillarray(int *vector, double value, int count);

/*__________________________________String functions______________________________________________*/

// Returns a substring of length len starting at index idx.
string strsub(string str, int idx, int len);

// Returns string length (number of characters).
long strlen(string str);

// Returns the position of first occurrence of substr in str.
long strfind(string str, string substr);

// Returns the position of last occurrence of substr in str.
long strrfind(string str, string substr);

// Find all occurrences of pattern in str and replace it with substr (in-place replacement, so new string is stored into str).
void strreplace(string str, string pattern, string substr);

// Converts a string to uppercase.
void strupr(string str);

// Converts a string to lowercase.
void strlwr(string str);

// Converts string to integer number. The first non-numerical character is considered the end of the input string and the remaining characters are ignored. If conversion failed, 2nd parameter is returned (or 0 if parameter is not set).
// long str2long(str [, default])
long str2long(string str);

// Converts string to a decimal number. The first non-numerical character is considered the end of the input string and the remaining characters are ignored. If conversion failed, 2nd parameter is returned (or 0 if parameter is not set).
// double str2double(str [, default])
double str2double(string str);

// Converts an integer number num to text. The optional parameter radix specifies the numerical system in which the conversion is to be performed (typically 10 or 16).
// If radix is not specified, default value is radix=10. The output string does not contain any identification of the numerical system used (e.g. the 0x prefix for the hexadecimal system).
// string long2str(num [, radix])
string long2str(long num);

// Converts a decimal number num to text.
string double2str(double num);

// Function copies the src string to the dest string. Implemented for compatibility with ANSI C. The construction dest=src yields the same result.
void strcpy(string dest, string src);

// Function appends a copy of the src string to the dest string. Implemented for compatibility with ANSI C. The construction dest=dest+src yields the same result.
void strcat(string dest, string src);

// Function compares strings str1 and str2. Implemented for compatibility with ANSI C. The construction str1==str2 yields the same result.
bool strcmp(string str1, string str2);

// Function for converting real number x into 4 elements of array buf. Each element represents an octet (byte) of number in single precision representation according to IEEE 754 (known as float).
// The function is useful for filling communication buffers. Optional 3rd parameter has the following meaning: 0 (default) = processor native endian, 1 = little endian, 2 = big endian.
// float2buf(buf,x[,endian])
void float2buf(int *buf, float x);

// Similar function to float2buf, but stores 8 elements in double precision format
// double2buf(buf,x[,endian])
void double2buf(int *buf, double x);

// Inverse function to float2buf
// double buf2float(buf[,endian])
double buf2float(int *buf);

// Inverse function to double2buf
// double buf2double(buf[,endian])
double buf2double(int *buf);

// Compares the str string with regular expression regexp. When the string matches the pattern, the capture array contains individual sections of the regular expression. capture[0] is always the complete regular expression. The function return the number of captured strings or a negative value in case of an error. The regular expression may contain the following:
//(?i) …Must be at the beginning of the regular expression. Makes the matching case-insensitive.
//^ …Match beginning of a string
//$ …Match end of a string
//() …Grouping and substring capturing
//\s …Match whitespace
//\S …Match non-whitespace
//\d …Match decimal digit
//\n …Match new line character
//\r …Match line feed character
//\f …Match vertical tab character
//\v …Match horizontal tab character
//\t …Match horizontal tab character
//\b …Match backspace character
//+ …Match one or more times (greedy)
//+? …Match one or more times (non-greedy)
//* …Match zero or more times (greedy)
//*? …Match zero or more times (non-greedy)
//? …Match zero or once (non-greedy)
// x|y …Match x or y (alternation operator)
//\meta …Match one of the meta characters: ^$().[]*+?|\
//\xHH …Match byte with hex value 0xHH, e.g. \x4a.
//[...] …] Match any character from the set. Ranges like [a-z are supported.
//[^...] …Match any character but the ones from the set.
long RegExp(string str, string regexp, string capture[]);

// The json string is supposed to contain text in JSON format. The names array contain the requested objects (subitems are accessed via ., index of the array via []). The values array then contains values of the requested objects.
// The cnt parameter defines the number of requested objects (length of both the names and values arrays). The function returns the number of values, negative numbers indicate errors.
long ParseJson(string json, int cnt, string names[], string values[]);

/*__________________________________System functions______________________________________________*/

// Stores a value into the archive subsystem. arc is a bit mask of archives to write the events to (e.g. for writting to archives 3,5 set arc=20 -> (BIN)10100 = (DEC)20). The archives are numbered from 1 and the maximum number of archives is limited to 15 (archive no. 0 is an internal system log).
// type:
// 1 …Bool
// 2 …Byte (U8)
// 3 …Short (I16)
// 4 …Long (I32)
// 5 …Word (U16)
// 6 …DWord (U32)
// 7 …Float (F32)
// 8 …Double (F64)
// 9 …Time
// 10 …Large (I64)
// 11 …Error
// 12 …String
// 17 …Bool Group
// 18 …Byte Group (U8)
// 19 …Short Group (I16)
// 20 …Long Group (I32)
// 21 …Word Group (U16)
// 22 …DWord Group (U32)
// 23 …Float Group (F32)
// 24 …Double Group (F64)
// 25 …Time Group
// 26 …Large Group (I64)
// 27 …Error Group
// id is a unique archive item ID. lvl_cnt is Alarm level in case of alarms or number of elements in case of Group type. value is a value to be written or an array reference in case of Group type.
void Archive(int arc, int type, int id, int lvl_cnt, int value);

// Displays the id value and the val value. The function is intended for debugging. The id is a user-defined constant (from 0 to 9999) for easy identification of the displayed message. The val can be of any data type including text string. The output can be found in the system log of REXYGEN.
void Trace(int id, string val);

// These commands are similar to the Trace command, only the output is routed to the corresponding logging group (Error, Warning, Verbose). Messages with the Error level are always written to the log. To view the Warning and Verbose messages, enable the corresponding message group. Go to the menu
void TraceError(int id, string val);

// These commands are similar to the Trace command, only the output is routed to the corresponding logging group (Error, Warning, Verbose). Messages with the Error level are always written to the log. To view the Warning and Verbose messages, enable the corresponding message group. Go to the menu
void TraceWarning(int id, string val);

// These commands are similar to the Trace command, only the output is routed to the corresponding logging group (Error, Warning, Verbose). Messages with the Error level are always written to the log. To view the Warning and Verbose messages, enable the corresponding message group. Go to the menu
void TraceVerbose(int id, string val);

// The script is suspended if its execution within the given sampling period takes more seconds than specified by the sec parameter. At the next start of the block the script continues from the point where it was suspended. Use Suspend(0) to suspend the code immediately.
void Suspend(int sec);

// Returns the sampling period of the block in seconds.
double GetPeriod();

// Returns the current time (in internal format). Intended for use with the ElapsedTime() function.
double CurrentTime();

// Returns the elapsed time in seconds (decimal number), i.e. the difference between the two time values new_time and old_time. The CurrentTime() function is typically used in place of the new_time parameter.
double ElapsedTime(double new_time, double old_time);

// Returns a pseudo-random number from the ⟨0,1) interval. The pseudo-random number generator is initialized prior to calling the init() function so the sequence is always the same.
double Random();

// Returns the quality of the var variable (see the QFC, QFD, VIN, VOUT blocks). The function is intended for use with the inputs, outputs and parameters. It always returns 0 for internal variables.
long QGet(int *var);

// Sets the quality of the var variable (see the QFC, QFD, VIN, VOUT blocks). The function is intended for use with the inputs, outputs and parameters. It has no meaning for internal variables.
void QSet(int *var, int value);

// Returns the quality of the var variable (see the QFC, QFD, VIN, VOUT blocks). The function is intended for use with the inputs, outputs and parameters. It always returns 0 for internal variables.
long QGet(double *var);

// Sets the quality of the var variable (see the QFC, QFD, VIN, VOUT blocks). The function is intended for use with the inputs, outputs and parameters. It has no meaning for internal variables.
void QSet(double *var, int value);

// Returns the quality resulting from merging of qualities of val1,…,valn. The basic rule for merging is that the resulting quality correspond with the worst quality of val1,…,valn. To obtain the same behavior as in other blocks of the REXYGEN system, use this function to set the quality of output, use all the signals influencing the output as parameters.
// long QPropag([n,]val1,…,valn)
long QPropag(val1, val2, ...);

// Reads a value from a file. A binary file with double values or a text file with values on individual lines is supposed. The idx index (binary file) or line number (text file) starts at 0. The file is identified by fileid. At present the following values are supported:
// 0 …file on a disk identified by the p0 parameter
// 1 …file on disk identified by name of the REXLANG block and extension .dat
// 2…file on a disk identified by the srcname parameter, but the extension is changed to .dat
// 3 …rexlang.dat file in the current directory
// 4-7 …same like 0-3, but format is text file. Each line contains one number. The index idx is the line number and starts at zero. Value idx=-1 means next line (e.g. sequential writing).
double LoadValue(int fileid, int idx);

// Stores the value to a file. The meaning of parameters is the same as in the LoadValue function.
void SaveValue(int fileid, int idx, string value);

// Returns the system time. The time is usually returned as UTC but this can be altered by the operating system settings. The time parameter must be an array of at least 8 items of type long.
// The function fills the array with the following values in the given order: year, month, day (in the month), day of week, hours, minutes, seconds, milliseconds. On some platforms the milliseconds value has a limited precision or is not available at all (the function returns 0 ms).
void GetSystemTime(int *time);

// Stop execution of the block’s algorithm (and whole task) for defined time. Use this block with extreme caution and only if there is no other possibility to achieve the desired behaviour of your algorithm.
// The sleep interval should not exceed 900 milliseconds. The shortest interval is about 0.01s, the precise value depends on the target platform.
void Sleep(double seconds);

// Returns the value of input/output/parameter of arbitrary block in REXYGEN algorithm. Such an external data item is referenced by the ItemID parameter. The structure of the string parameter ItemID is the same as in e.g. the sc parameter of the GETPI function block.
// If the value cannot be obtained (e.g. invalid or non-existing ItemID, data type conflict, etc.), the REXLANG block issues an error and must be reset.
long GetExtInt(int ItemID);

// See GetExtInt(ItemID).
long GetExtLong(int ItemID);

// Similar to GetExtInt(ItemID) but for decimal numbers.
double GetExtReal(int ItemID);

// See GetExtReal(ItemID).
double GetExtDouble(int ItemID);

// Similar to GetExtInt(ItemID) but for strings.
string GetExtString(int ItemID);

// Sets the input/output/parameter of arbitrary block in REXYGEN algorithm to value. Such an external data item is referenced by the ItemID parameter. The structure of the string parameter ItemID is the same as in e.g. the sc parameter of the SETPI function block.
// The type of the external data item (long/double/string) must correspond with the type of the value parameter. If the value cannot be set (e.g. invalid or non-existing ItemID, data type conflict, etc.), the REXLANG block issues an error and must be reset.
void SetExt(int ItemID, string value);

// Function browses task adress space. If ItemID is a block identifier (block_path), subitems string array will contain names of all inputs, outputs, parameters and internal states. Function returns number of subitems or negative error code.
// kinds values: executive = 0, module = 1, driver = 2, archive = 3, level = 4, task = 5, quicktask = 6, subsystem = 7, block = 8, input = 9, output = 10, internal state = 11, parameter or state array = 12, special = 13.
int BrowseExt(int ItemID, int first_subitem_index, int max_count, int *subitems, int kinds);

// Run (one step) arbitrary block in REXYGEN algorithm. Such an external block is referenced by the ItemID parameter. The structure of the string parameter ItemID is the same as in e.g. the sc parameter of the GETPI function block. The function returns result code of the calling block (see REXYGEN error codes).
// It is strongly recommended to call halted blocks only (set checkbox Halt on the property page Runtime in the parameters dialog of the block) and the block (or subsystem) should be in same task as the REXLANG block.
long CallExt(int ItemID);

// Returns the number of rows of the array that is attached to the input with index input of the REXLANG block.
long GetInArrRows(int inputIndex);

// Returns the number of columns of the array that is attached to the input with index input of the REXLANG block.
long GetInArrCols(int inputIndex);

// Returns the member of the array that is attached to the input with index input of the REXLANG block.
double GetInArrDouble(int inputIndex, int row, int col);

// Sets the member of the array that is attached to the input with index input of the REXLANG block.
void SetInArrValue(int inputIndex, int row, int col, string value);

// Sets the dimension of the array that is attached to the input with index input of the REXLANG block.
void SetInArrDim(int inputIndex, int row, int col);

// Reading physical memory. Get the handle by Open(72,"/dev/mem",<physical address>,<area size>).
long memrd32(int *hMem, int offset);

// Writing to physical memory. Get the handle by OpenMemory("/dev/mem",<physical address>,<area size>).
long memwr32(int *hMem, int offset, string value);

/*__________________________________Communication functions_______________________________________*/

// Function for opening a file. Identification number (the so-called handle) of the file is returned. If a negative value is returned, the opening was not successful.
long OpenFile(string filename);

// Function for opening a serial line. Identification number (the so-called handle) of serial port is returned. If a negative value is returned, the opening was not successful. Parity setting: 0=none, 1=odd, 2=even.
long OpenCom(string comname, long baudrate, long parity);

// Function for opening a UDP socket. Identification number (the so-called handle) of the socket is returned. If a negative value is returned, the opening was not successful.
long OpenUDP(string localname, long lclPort, string remotename, long remPort);

// Function for opening a TCP socket (server, listening). Identification number (the so-called handle) of the socket is returned. If a negative value is returned, the opening was not successful.
long OpenTCPsvr(string localname, long lclPort);

// Function for opening a TCP socket (client). Identification number (the so-called handle) of the socket is returned. If a negative value is returned, the opening was not successful.
long OpenTCPcli(string remotename, long remPort);

// Function for opening the I2C bus. Identification number (the so-called handle) of the bus is returned. If a negative value is returned, the opening was not successful.
long OpenI2C(string devicename);

// Function for opening the SPI bus. Identification number (the so-called handle) of the bus is returned. If a negative value is returned, the opening was not successful.
long OpenSPI(string devicename);

// Function for mapping physical memory. Identification number (the so-called handle) of the memory address is returned. If a negative value is returned, the opening was not successful.
long OpenMemory(string devicename, long baseaddr, long size);

// Closes the socket, serial line, file or any device opened by the Open... functions.
long Close(long handle);

// Sets the parameters of a socket or serial line. The array size must be at least:
// 22  -for serial line,
//
// 2   -for file (1st item is mode: 1=seek begin, 2=seek current, 3=seek end, 4=set file end, 2nd item is offset for seek),
//
// 3   -for SPI (1st item is SPI mode, 2nd item is bits per word, 3rd item is max speed in Hz),
//
// 5   -for I2C (1st item is slave address, 2nd item is 10-bit address flag, 3rd item is Packet Error Checking flag, 4th item is nuber of retries, 5th item is timeout)
void SetOptions(long handle, long params[]);

// Reads parameters of a socket or serial line to the params array. The array size must be big enough, at least 2 for files, 2 for a socket and 22 for serial line (see SetOptions).
void GetOptions(long handle, long param, ...);

// Accepts the connection to listening socket hListen invoked by the client. A communication socket handle or an error is returned.
long Accept(long hListen);

// Receives data from a serial line or socket. The count parameter defines the maximum number of bytes to read. The count of bytes read or an error code is returned. Each byte of incoming data is put to the buffer array of type long in the corresponding order.
//
// It is also possible to use the form
// long Read(long handle, string data[], long count) (i.e. a string is used instead of a data array; one byte in the input file corresponds to one character; not applicable to binary files).
// The error codes are:
//-1	it is necessary to wait for the operation to finish (the function is "non-blocking")
//
//-309	reading failed; the operating system error code appears in the log (when function block logging is enabled)
//
//-307	file/socket is not open
long Read(long handle, long buffer[], long count);

// Sends the data to a serial line or socket. The count parameter defines the number of bytes to send. The count of bytes or en error code sent is returned. Each byte of outgoing data is read from the buffer array of type long in the corresponding order.
//
// It is also possible to use the form
// long Write(long handle, string data) (i.e. a string is used instead of a data array; one byte in the output file corresponds to one character; not applicable to binary files).
// The error codes are:
//-1	it is necessary to wait for the operation to finish (the function is "non-blocking")
//-310	write failed; the operating system error code appears in the log (when function block logging is enabled)
//-307	file/socket is not open
long Write(long handle, long buffer[], long count);

// Read one line from (text) file, serial line or socket; read characters are in the variable data up to allocated size of the string;
// the function return real size (number of bytes) of line or error code.
long ReadLine(long handle, string data);

// Delete file. Return 0 if success; negative value is error code.
long DeleteFile(string filename);

// Rename file. Return 0 if success; negative value is error code.
long RenameFile(string filename, string newfilename);

// Return true if file or device exist (is it possible to open it for reading).
bool ExistFile(string filename);

// Communication over the I2C bus. Works only in Linux operating system on devices with the I2C bus (e.g. Raspberry Pi). Sends and receives data to/from the slave device with address addr.
// The parameter handle is returned by the OpenI2C function, whose parameter defines the device name (according to the operating system).
// The parameter bufW is a buffer (an array) for the data which is sent out, cntW is the number of bytes to send out, bufR is a buffer (an array) for the data which comes in and cntR is the number of bytes to receive.
// The function returns 0 or an error code.
long I2C(long handle, long addr, long bufW[], long cntW, long bufR[], long cntR);

// Execution of one transaction over the SPI bus. Works only in Linux operating system on devices with the SPI bus (e.g. Raspberry Pi). The parameter handle is returned by the OpenSPI function, whose parameter defines the device name (according to the operating system).
// The second parameter is always 0 (reserved for internal use). The parameter bufW is a buffer (an array) for the data which is sent out, cntW is the number of bytes to send out, bufR is a buffer (an array) for the data which comes in and cntR is the number of bytes to receive.
// Note that SPI communication is full-duplex, therefore the resulting length of the SPI transaction is given by maximum of the cntW and cntR parameters, not their sum.
// The function returns 0 or an error code.
long SPI(long handle, 0, long bufW[], long cntW, long bufR[], long cntR);

// Set position for Read/Write command. Parameter mode means: 1=offset from begin of the file, 2= offset from current position, 3=offset from end of the file.
long Seek(long handle, long mode[], long offset);

// Obsolete function. Use Read instead.
long Recv(long handle, long buffer[], long count);

// Obsolete function. Use Write instead.
long Send(long handle, long buffer[], long count);

// Compute 16-bit cyclic redundand code that is used as checksum/hash in many comunication protocols.
// Data byte array (represented by long array) or string to compute hash length number of bytes in input array/text (could be -1 for whole string) init so called initial vector poly so called control polynom flags 1...revert bit order (in input bytes as so as in result crc), 2...result crc is xored with 0xFFFF,
// 4...if data is long array, all 4 bytes in long are procesed (LSB first), 8... same like 4, but MSB first offset index of the first processed byte in data array (usually 0)
// Notice: there is same function for 32-bit CRC long crc32(data,length,init,poly,flags,offset), and for 8-bit CRC long crc8(data,length,init,poly,flags,offset). Initial vector, control polynom, flags for many protocols could be found on https://crccalc.com/ Examples: MODBUS: crc16("123456789",-1,0xFFFF,0x8005,1,0)); DECT-X: crc16("123456789",-1,0,0x0589,0,0));
long crc16(int *data, int length, int *init, int *poly, int flags, int offset);

// Compute 32-bit cyclic redundand code that is used as checksum/hash in many comunication protocols.
// Data byte array (represented by long array) or string to compute hash length number of bytes in input array/text (could be -1 for whole string) init so called initial vector poly so called control polynom flags 1...revert bit order (in input bytes as so as in result crc), 2...result crc is xored with 0xFFFF,
// 4...if data is long array, all 4 bytes in long are procesed (LSB first), 8... same like 4, but MSB first offset index of the first processed byte in data array (usually 0)
// Notice: there is same function for 16-bit CRC long crc16(data,length,init,poly,flags,offset), and for 8-bit CRC long crc8(data,length,init,poly,flags,offset). Initial vector, control polynom, flags for many protocols could be found on https://crccalc.com/ Examples: MODBUS: crc16("123456789",-1,0xFFFF,0x8005,1,0)); DECT-X: crc16("123456789",-1,0,0x0589,0,0));
long crc32(int *data, int length, int *init, int *poly, int flags, int offset);

// Compute 8-bit cyclic redundand code that is used as checksum/hash in many comunication protocols.
// Data byte array (represented by long array) or string to compute hash length number of bytes in input array/text (could be -1 for whole string) init so called initial vector poly so called control polynom flags 1...revert bit order (in input bytes as so as in result crc), 2...result crc is xored with 0xFFFF,
// 4...if data is long array, all 4 bytes in long are procesed (LSB first), 8... same like 4, but MSB first offset index of the first processed byte in data array (usually 0)
// Notice: there is same function for 32-bit CRC long crc32(data,length,init,poly,flags,offset), and for 16-bit CRC long crc16(data,length,init,poly,flags,offset). Initial vector, control polynom, flags for many protocols could be found on https://crccalc.com/ Examples: MODBUS: crc16("123456789",-1,0xFFFF,0x8005,1,0)); DECT-X: crc16("123456789",-1,0,0x0589,0,0));
long crc8(int *data, int length, int *init, int *poly, int flags, int offset);