# Disk Space Analyzer (proj1.sh)

A Bash script that helps analyze disk space usage by finding the largest files in a directory and optionally deleting them.

## Features

- 📊 Lists the top N largest files in a specified directory
- 🗑️ Interactive file deletion with confirmation
- 📝 Logs all file deletions with timestamps
- ✅ Input validation for directories and files
- 🔍 Handles errors gracefully

## Prerequisites

- Bash shell
- `du` command (for disk usage analysis)
- `sort` command (for sorting files by size)
- Basic Unix/Linux utilities

## Usage

1. Make the script executable:
   ```bash
   chmod +x proj1.sh
   ```

2. Run the script:
   ```bash
   ./proj1.sh
   ```

3. Follow the interactive prompts:
   - Enter the directory path to analyze
   - Specify how many largest files to display
   - Choose whether to delete any files

## How It Works

1. **Directory Validation**: Checks if the specified directory exists
2. **Size Analysis**: Uses `du -ah` to calculate file sizes recursively
3. **Sorting**: Sorts files by size in descending order using `sort -rh`
4. **Display**: Shows the top N largest files with their sizes
5. **Interactive Deletion**: Prompts for file deletion with confirmation
6. **Logging**: Records all deletions in `log.txt` with timestamps

## Output Files

- `log.txt` - Contains a log of all deleted files with timestamps

## Example Usage

```
Enter directory path: /home/user/Downloads
Enter the number of largest files to display: 5

Top 5 largest files in /home/user/Downloads:
2.5G    /home/user/Downloads/movie.mp4
1.2G    /home/user/Downloads/backup.zip
500M    /home/user/Downloads/presentation.pptx
...

Do you want to delete any file? (yes/no)
yes
Enter the file name (full path) to delete: 
/home/user/Downloads/old-backup.zip
```

## Safety Features

- Confirms file deletion with `rm -i` (interactive mode)
- Validates directory and file existence before operations
- Provides clear error messages
- Logs all actions for audit purposes

## Use Cases

- Clean up disk space by identifying large files
- Analyze directory sizes for storage management
- Maintain audit trails of file deletions
- Quick disk space cleanup with safety checks