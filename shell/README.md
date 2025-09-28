# Shell Programming Exercises

A comprehensive collection of 32+ shell programming exercises covering fundamental to advanced Bash scripting concepts. These exercises are designed for learning, practice, and demonstrating various shell scripting techniques.

## 📚 Exercise Structure

This directory contains systematic shell programming exercises organized by complexity and topic area:

### 🔢 **Questions 1-10: Fundamentals**
Basic shell scripting concepts including variables, arrays, input/output, and simple operations.

| Script | Topic | Description |
|--------|-------|-------------|
| `q1.sh` | Array Sorting | Read numbers, display them, and sort in ascending/descending order with bubble sort |
| `q2.sh` | Basic Operations | Fundamental shell operations and variable handling |
| `q3.sh` | Input/Output | Reading user input and displaying formatted output |
| `q4.sh` | Arithmetic | Basic arithmetic operations and calculations |
| `q5.sh` | Functions & Conditionals | Address printing function and number checking |
| `q6.sh` | String Operations | String manipulation and processing |
| `q7.sh` | File Operations | Basic file handling and processing |
| `q8.sh` | Loops | For and while loop implementations |
| `q9.sh` | Variables | Variable scope and manipulation |
| `q10.sh` | Parameter Handling | Command-line argument processing |

### 🔄 **Questions 11-20: Control Structures**
Advanced control flow, loops, functions, and decision-making structures.

| Script | Topic | Description |
|--------|-------|-------------|
| `q11.sh` | Advanced Loops | Nested loops and complex iterations |
| `q12.sh` | Case Statements | Multi-option menu systems |
| `q13.sh` | Function Design | Modular programming with functions |
| `q14.sh` | Error Handling | Input validation and error management |
| `q15.sh` | Mathematical Computing | Quadratic equation solver with complex roots |
| `q16.sh` | Pattern Matching | Regular expressions and pattern operations |
| `q17.sh` | Array Operations | Advanced array manipulations |
| `q18.sh` | String Processing | Complex string operations and transformations |
| `q19.sh` | File Processing | Advanced file operations and filtering |
| `q20.sh` | System Integration | Combining multiple system commands |

### 🚀 **Questions 21-32: Advanced Topics**
System administration, automation, and complex programming concepts.

| Script | Topic | Description |
|--------|-------|-------------|
| `q21.sh` | Process Management | System process monitoring and control |
| `q22.sh` | File Permissions | Permission management and security |
| `q23.sh` | System Monitoring | Resource monitoring and reporting |
| `q24.sh` | Text Processing | Advanced text manipulation with sed/awk |
| `q25.sh` | Interactive Menus | System information menu with pwd, users, calendar |
| `q26.sh` | Data Structures | Complex data handling and processing |
| `q27.sh` | Network Operations | Network-related shell operations |
| `q28.sh` | Log Processing | Log file analysis and reporting |
| `q29.sh` | Backup Systems | Automated backup and archive operations |
| `q30.sh` | System Administration | Advanced system admin tasks |
| `q31.sh` | Automation Scripts | Complex automation workflows |
| `q32.sh` | Mathematical Tables | Multiplication tables and cube calculations |

## 🎯 Learning Objectives

These exercises cover essential shell scripting concepts:

### **Core Concepts**
- ✅ Variables and data types
- ✅ Arrays and associative arrays
- ✅ Input/output operations
- ✅ Command-line arguments
- ✅ Environment variables

### **Control Structures**
- ✅ Conditional statements (if/else)
- ✅ Case statements and menus
- ✅ For and while loops
- ✅ Nested loops and break/continue
- ✅ Function definitions and calls

### **Advanced Topics**
- ✅ File and directory operations
- ✅ Text processing and regex
- ✅ System command integration
- ✅ Error handling and validation
- ✅ Mathematical computations
- ✅ Process and system management

### **Best Practices**
- ✅ Code organization and modularity
- ✅ Input validation and error handling
- ✅ User-friendly interfaces
- ✅ Efficient algorithms and logic
- ✅ System integration techniques

## 🚀 Getting Started

### Prerequisites
- Bash shell (version 4.0+)
- Basic Unix/Linux utilities
- Text editor for modifications
- Calculator utility (`bc`) for mathematical operations

### Running the Exercises

1. **Make scripts executable:**
   ```bash
   chmod +x *.sh
   ```

2. **Run any exercise:**
   ```bash
   ./q1.sh    # Array sorting exercise
   ./q15.sh   # Quadratic equation solver
   ./q25.sh   # Interactive system menu
   ```

3. **Run all exercises in sequence:**
   ```bash
   for i in {1..32}; do
       echo "Running q$i.sh..."
       ./q$i.sh
   done
   ```

## 📁 Additional Resources

### **Subdirectories**
- `22B-CO-023/` - Course-specific materials
- `jjf/` - Personal practice scripts
- `projects/` - Additional project files

### **Practice Files**
- `jjf.txt` - Sample data file for testing
- Various subdirectories with additional exercises

## 💡 Usage Examples

### **Array Sorting (q1.sh)**
```bash
./q1.sh
# Input: 5 2 8 1 9
# Output: 
# Original: 5 2 8 1 9
# Ascending: 1 2 5 8 9
# Descending: 9 8 5 2 1
```

### **Quadratic Equation Solver (q15.sh)**
```bash
./q15.sh
# Input: a=1, b=-5, c=6
# Output: Roots are real and different: 3.00, 2.00
```

### **Interactive System Menu (q25.sh)**
```bash
./q25.sh
# Menu:
# a) Display present working directory
# b) Display users of the system  
# c) Display calendar of the year
# d) Exit
```

## 🔧 Customization

Feel free to modify these exercises:
- Add additional functionality
- Improve error handling
- Enhance user interfaces
- Combine multiple exercises
- Create your own variations

## 📈 Learning Path

### **Beginner Path** (Start here)
1. `q1.sh` - `q5.sh`: Basic operations and syntax
2. `q6.sh` - `q10.sh`: Variables and simple functions

### **Intermediate Path**
1. `q11.sh` - `q15.sh`: Control structures and math
2. `q16.sh` - `q20.sh`: String and file processing

### **Advanced Path**
1. `q21.sh` - `q25.sh`: System administration
2. `q26.sh` - `q32.sh`: Complex automation

## 🤝 Contributing

These exercises can be enhanced with:
- Additional test cases
- Better error handling
- More comprehensive documentation
- Performance optimizations
- Additional features

## 📝 Notes

- All scripts are educational and safe to run
- Some scripts may require user input
- Mathematical operations use `bc` calculator
- System information commands are read-only
- Scripts follow standard bash conventions

---

*These exercises provide a comprehensive foundation in shell scripting from basic concepts to advanced system administration tasks.*