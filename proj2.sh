#!/bin/bash

VAULT_DIR="$HOME/vault_store"
LOG_FILE="$HOME/vault_store/vault.log"
mkdir -p "$VAULT_DIR"
touch "$LOG_FILE"

log_action() {
    echo "$(date) - $1" >> "$LOG_FILE"
}

add_file() {
    read -p "Enter path of the file to add: " filepath
    if [[ -f "$filepath" ]]; then
        filename=$(basename "$filepath")
        gpg -c --output "$VAULT_DIR/$filename.gpg" "$filepath"
        log_action "Encrypted and added: $filename"
        echo "File encrypted and added to vault."
    else
        echo "File does not exist."
    fi
}

list_files() {
    echo "Encrypted files in vault:"
    ls "$VAULT_DIR" | grep ".gpg$"
}

decrypt_file() {
    read -p "Enter the name of the file to decrypt (without .gpg): " filename
    fullpath="$VAULT_DIR/$filename.gpg"
    if [[ -f "$fullpath" ]]; then
        gpg -o "./$filename" -d "$fullpath"
        log_action "Decrypted file: $filename"
        echo "File decrypted to current directory."
    else
        echo "Encrypted file not found."
    fi
}

delete_file() {
    read -p "Enter the name of the file to delete (without .gpg): " filename
    fullpath="$VAULT_DIR/$filename.gpg"
    if [[ -f "$fullpath" ]]; then
        rm -i "$fullpath"
        log_action "Deleted file: $filename"
        echo "File deleted from vault."
    else
        echo "File not found."
    fi
}

while true; do
    echo -e "\n===== Secure File Vault ====="
    echo "1. Add file to vault"
    echo "2. List encrypted files"
    echo "3. Decrypt a file"
    echo "4. Delete a file"
    echo "5. View log"
    echo "6. Exit"
    read -p "Choose an option [1-6]: " choice

    case $choice in
        1) add_file ;;
        2) list_files ;;
        3) decrypt_file ;;
        4) delete_file ;;
        5) cat "$LOG_FILE" ;;
        6) echo "Exiting..."; exit 0 ;;
        *) echo "Invalid option. Try again." ;;
    esac
done
