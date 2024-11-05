# Database Management System from scratch, using C.

*“What I cannot create, I do not understand.” – Richard Feynman*

---

## Introduction 

I'm bored and I'd love to work.
A Database Management System (DBMS) is software that enables users and applications to store, retrieve, and manipulate data efficiently. 
It serves as an interface between end-users or applications and the database itself, managing how data is structured, stored, and accessed.

---

## Questions

How does a database work?
What format is the data saved in?
When does data move from memory to disk?
How do we receive data so fast?

---

## Process of a Database

frontend: 
    input: an SQL query 
    output: virtual machine bytecode

backend: 
    - **Virtual Machine** takes bytecode and operates on tables or indexes made up of **b-trees**
    - Each **B-Tree** is made up of many nodes, each node is one page long.
    - a **Pager** receives commands to write or read pages of data.


### REPL: Read, Execute, Print, Repeat

this is a simple while loop to execute the command entered. 

---

## Plan of Execution

[ ] - Core Features
[ ] - File Structure: Modules     
[ ] - Implement The Basic Storage Layer: File Based Storage.
[ ] - Create a simple query interface.
[ ] - Data Insertion & Data retrieval
[ ] - Basic Indexing System: 
[ ] - Support for Data Types (simple)
[ ] - Query Execution
[ ] - Concurrency Control
[ ] - Transaction Management
[ ] - Finetune the CLI Interface
[ ] - Buffering and Caching / Better Performance
[ ] - Support SQL syntax
[ ] - Tests 
[ ] - Documentation
[ ] - Extend

---

## Core Features


**Data Storage and Retrieval**
File-based data storage
Serialization and deserialization of records
Efficient data retrieval from files

**Query Parsing and Execution**
Basic query parsing for commands like INSERT, SELECT, UPDATE, and DELETE
Query execution engine to process parsed commands and route them to the appropriate modules

**Data Insertion and Deletion**
Insert new records into storage
Delete records based on specified conditions

**Data Retrieval and Filtering**
Implement SELECT with filtering conditions (e.g., WHERE clauses)
Support for selecting specific columns or entire records

**Indexing**
Basic indexing to improve query performance, such as B-tree or hash indexes
Index maintenance for insertion, deletion, and updates

**Transaction Management**
Basic transaction support for handling multiple changes as a single unit of work
Logging and rollback mechanisms for data integrity

**Concurrency Control**
Locking mechanisms (e.g., read and write locks) to manage multi-user access safely
Deadlock prevention techniques to handle simultaneous transactions

**Data Types and Schema Support**
Support for basic data types (e.g., int, float, string)
Simple schema definition to enforce data types for each column

**Error Handling and Validation**
Error detection and user-friendly error messages
Data validation for type consistency and schema compliance

**Index Management**
Creation and management of indexes for faster data access
Maintenance of indexes during record insertion, deletion, and updates

**Memory Management and Optimization**
Buffering and caching mechanisms for frequently accessed data
Efficient memory usage for large datasets

**Basic SQL Syntax Support**
Parsing additional SQL commands (e.g., JOIN, GROUP BY, ORDER BY)
Expansion of query parser to support more complex queries

**Logging and Recovery**
Persistent logging of transactions for recovery in case of crashes
Recovery mechanisms to restore data to a consistent state

**Simple Security Features**
Basic user authentication and access control
Permissions for read, write, and delete operations

**User Interface (Command-Line Interface)**
A basic CLI for user interaction and query input
Output formatting for query results

**Performance Monitoring and Profiling**
Query profiling to identify slow operations
Optimization tools to improve data access and processing times


---

## Resources:

[C: Build your own Database from Scratch](https://cstack.github.io/db_tutorial/)
[Go: Build your own Database from Scratch](https://build-your-own.org/database/)
[Sqlite Database system, design and Implementation](https://books.google.com.co/books?id=OEJ1CQAAQBAJ&printsec=frontcover&redir_esc=y#v=onepage&q&f=false)
[SQLite documentation](https://www.sqlite.org/arch.html)
