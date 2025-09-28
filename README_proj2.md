# Secure File Vault (proj2.sh)

A Bash script that provides a secure file storage system using GPG encryption. Store, encrypt, decrypt, and manage files in a password-protected vault.

## Features

- 🔐 **GPG Encryption**: Files are encrypted using GPG symmetric encryption
- 🗂️ **Vault Management**: Centralized storage in `~/vault_store/`
- 📋 **File Operations**: Add, list, decrypt, and delete encrypted files
- 📝 **Activity Logging**: Complete audit trail of all vault operations
- 🖥️ **Interactive Menu**: User-friendly command-line interface
- 🔒 **Password Protection**: Each file requires a passphrase for encryption/decryption

## Prerequisites

- Bash shell
- GPG (GNU Privacy Guard) installed
  - Ubuntu/Debian: `sudo apt install gnupg`
  - CentOS/RHEL: `sudo yum install gnupg2`
  - macOS: `brew install gnupg`

## Installation & Setup

1. Make the script executable:
   ```bash
   chmod +x proj2.sh
   ```

2. Run the script:
   ```bash
   ./proj2.sh
   ```

The script will automatically create the vault directory (`~/vault_store/`) and log file on first run.

## Usage

The script provides an interactive menu with the following options:

### 1. Add File to Vault
- Encrypts any file using GPG symmetric encryption
- Stores encrypted version in the vault
- Prompts for a passphrase during encryption

### 2. List Encrypted Files
- Shows all `.gpg` files currently in the vault
- Displays only the encrypted filenames

### 3. Decrypt a File
- Decrypts a file from the vault to the current directory
- Requires the correct passphrase
- Keeps the encrypted version in the vault

### 4. Delete a File
- Permanently removes an encrypted file from the vault
- Includes confirmation prompt for safety

### 5. View Log
- Displays the complete activity log
- Shows timestamps for all vault operations

### 6. Exit
- Safely exits the application

## Directory Structure

```
~/vault_store/
├── vault.log          # Activity log file
├── document1.txt.gpg  # Encrypted files
├── photo.jpg.gpg
└── backup.zip.gpg
```

## Example Session

```
===== Secure File Vault =====
1. Add file to vault
2. List encrypted files
3. Decrypt a file
4. Delete a file
5. View log
6. Exit
Choose an option [1-6]: 1
Enter path of the file to add: /home/user/important.txt
Enter passphrase: [hidden]
File encrypted and added to vault.

===== Secure File Vault =====
Choose an option [1-6]: 2
Encrypted files in vault:
important.txt.gpg
```

## Security Features

- **Symmetric Encryption**: Uses GPG with user-defined passphrases
- **No Key Storage**: Passphrases are not stored anywhere
- **Audit Trail**: Complete logging of all operations
- **Safe Deletion**: Confirmation prompts before file removal
- **Isolated Storage**: All encrypted files stored in dedicated directory

## Important Notes

- **Remember Your Passphrases**: Without the correct passphrase, encrypted files cannot be recovered
- **Backup**: Consider backing up your `~/vault_store/` directory
- **Passphrase Strength**: Use strong, unique passphrases for each file
- **Log Security**: The log file contains timestamps but no sensitive information

## Use Cases

- Secure storage of sensitive documents
- Password-protected file backup
- Confidential data archiving
- Multi-user secure file sharing (with shared passphrases)
- Personal encryption workflow

## Troubleshooting

### GPG Not Found
```bash
# Install GPG first
sudo apt install gnupg  # Ubuntu/Debian
sudo yum install gnupg2 # CentOS/RHEL
```

### Permission Issues
```bash
# Fix vault directory permissions
chmod 700 ~/vault_store/
```

### Decryption Fails
- Verify you're using the correct passphrase
- Check that the encrypted file exists in the vault
- Ensure GPG is properly configured