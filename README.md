# Shell Programming Projects (Bash/Bourne)

A collection of practical Bash shell scripts for system administration, file management, and security operations. These projects demonstrate various shell scripting techniques including file operations, encryption, logging, and interactive user interfaces.

## 📋 Projects Overview

| Project | Description | Key Features |
|---------|-------------|--------------|
| [**Disk Space Analyzer**](#-disk-space-analyzer-proj1sh) | Analyze disk usage and manage large files | File size analysis, interactive deletion, logging |
| [**Secure File Vault**](#-secure-file-vault-proj2sh) | GPG-encrypted file storage system | Encryption, secure storage, audit trails |

## 🔍 Disk Space Analyzer (`proj1.sh`)

A powerful disk space analysis tool that helps identify and manage large files in your system.

### Features
- 📊 **Size Analysis**: Find the largest files in any directory
- 🗑️ **Safe Deletion**: Interactive file removal with confirmation
- 📝 **Activity Logging**: Complete audit trail of deletions
- ✅ **Input Validation**: Robust error handling and validation
- 🔍 **Recursive Scanning**: Deep directory analysis

### Quick Start
```bash
chmod +x proj1.sh
./proj1.sh
```

### Use Cases
- System cleanup and maintenance
- Storage optimization
- Disk space troubleshooting
- File management auditing

---

## 🔐 Secure File Vault (`proj2.sh`)

A GPG-based secure file storage system with encryption and comprehensive vault management.

### Features
- 🔒 **GPG Encryption**: Military-grade symmetric encryption
- 🗂️ **Vault Management**: Centralized secure storage
- 📋 **File Operations**: Add, list, decrypt, delete files
- 📝 **Activity Logging**: Complete operation audit trail
- 🖥️ **Interactive Interface**: User-friendly menu system
- 🔐 **Password Protection**: Individual file passphrases

### Quick Start
```bash
chmod +x proj2.sh
./proj2.sh
```

### Use Cases
- Secure document storage
- Confidential file backup
- Multi-user secure sharing
- Personal encryption workflow

---

## 🚀 Getting Started

### Prerequisites
- **Bash shell** (version 4.0+)
- **Standard Unix utilities** (`du`, `sort`, `grep`)
- **GPG** (for Secure File Vault)
  ```bash
  # Ubuntu/Debian
  sudo apt install gnupg
  
  # CentOS/RHEL
  sudo yum install gnupg2
  
  # macOS
  brew install gnupg
  ```

### Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/JosephJonathanFernandes/Shell-Programming-Projects-Bash-Or-Bourne.git
   cd Shell-Programming-Projects-Bash-Or-Bourne
   ```

2. Make scripts executable:
   ```bash
   chmod +x *.sh
   ```

3. Run any project:
   ```bash
   ./proj1.sh  # Disk Space Analyzer
   ./proj2.sh  # Secure File Vault
   ```

## 📖 Detailed Documentation

Each project includes comprehensive documentation:
- [`README_proj1.md`](README_proj1.md) - Disk Space Analyzer detailed guide
- [`README_proj2.md`](README_proj2.md) - Secure File Vault detailed guide

## 🛠️ Technical Highlights

### Shell Scripting Techniques Demonstrated
- **Interactive Input Handling**: User prompts and validation
- **File System Operations**: Directory traversal and file manipulation
- **Error Handling**: Comprehensive validation and error messages
- **Logging Systems**: Timestamp-based activity logging
- **Menu Systems**: Interactive command-line interfaces
- **Security Integration**: GPG encryption workflows
- **Process Control**: Safe file operations with confirmations

### Code Quality Features
- ✅ Input validation and sanitization
- ✅ Error handling and graceful failures
- ✅ Comprehensive logging
- ✅ User-friendly interfaces
- ✅ Security best practices
- ✅ Modular function design

## 🔒 Security Considerations

### Disk Space Analyzer
- Interactive deletion confirmations
- Safe file removal with `rm -i`
- Directory existence validation
- Comprehensive audit logging

### Secure File Vault
- GPG symmetric encryption
- No passphrase storage
- Isolated vault directory
- Complete operation logging
- Secure file handling

## 🤝 Contributing

Contributions are welcome! Please feel free to submit issues, feature requests, or pull requests.

### Development Guidelines
- Follow existing code style
- Add comprehensive error handling
- Include logging for important operations
- Write clear, self-documenting code
- Test on multiple shell environments

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 👨‍💻 Author

**Joseph Jonathan Fernandes**
- GitHub: [@JosephJonathanFernandes](https://github.com/JosephJonathanFernandes)

## 🌟 Support

If you find these projects helpful, please consider:
- ⭐ Starring this repository
- 🐛 Reporting issues
- 💡 Suggesting new features
- 🤝 Contributing improvements

---

*These projects demonstrate practical shell scripting for real-world system administration and security tasks. Each script is designed with safety, usability, and maintainability in mind.*