# <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Laptop.png" alt="Laptop" width="40" height="40" /> Master Data Structures & Algorithms in C++

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=600&size=30&pause=1000&color=007ACC&center=true&vCenter=true&random=false&width=700&lines=Welcome+to+my+DSA+Practice+Repository!;Mastering+Data+Structures...;Cracking+Complex+Algorithms!;Writing+Efficient+C%2B%2B+Code!;" alt="Typing SVG" />
</p>

## 🚀 About This Repository
This repository contains my personal journey, practice materials, and solutions for **Data Structures and Algorithms** using **C++**. 
The goal is to deeply understand how data is organized, stored, and manipulated to write highly efficient software.

---

## 🧠 Core Data Structures
A **Data Structure** is a specialized format for organizing, processing, retrieving and storing data. Here are the core structures we explore:

<details open>
<summary><b>1. Arrays & Vectors</b></summary>
<br>
Contiguous blocks of memory holding elements of the same type. Fast access, but slower insertions and deletions in the middle.
</details>

<details open>
<summary><b>2. Linked Lists</b></summary>
<br>
Nodes connected by pointers. They do not require contiguous memory, making insertions and deletions very fast, though random access is slower.

```mermaid
graph LR
    A((Head: 10)) --> B((Node: 20))
    B --> C((Node: 30))
    C --> D((Null))
    style A fill:#f9f,stroke:#333,stroke-width:2px
    style D fill:#ccc,stroke:#333,stroke-width:2px
```
</details>

<details open>
<summary><b>3. Trees & Binary Search Trees (BST)</b></summary>
<br>
Hierarchical data structures with a root node and children. Extremely powerful for fast lookups and hierarchical data mapping.

```mermaid
graph TD
    A((8)) --> B((3))
    A --> C((10))
    B --> D((1))
    B --> E((6))
    E --> F((4))
    E --> G((7))
    C --> H((14))
    H --> I((13))
    
    style A fill:#bbf,stroke:#333,stroke-width:2px
```
</details>

---

## ⚡ Essential Algorithms
An **Algorithm** is a step-by-step procedure for solving a problem or performing a computation.

### 🔄 Sorting Algorithms
- **Merge Sort**: A divide-and-conquer algorithm that divides the array into halves, recursively sorts them, and merges them. `Time: O(N log N)`
- **Quick Sort**: Picks a pivot and partitions the array around the pivot. `Time: O(N log N) average`
- **Bubble / Selection / Insertion Sort**: Fundamental sorting algorithms primarily used for educational purposes due to their `O(N²)` time complexities.

### 🔍 Searching Algorithms
- **Linear Search**: Checks every element sequentially from the start to the end. `Time: O(N)`
- **Binary Search**: Efficiently searches a **sorted array** by repeatedly dividing the search interval in half. `Time: O(log N)`

---

## 📂 Repository Organization Strategy
This repository strictly follows an isolated branching strategy to keep learning modules completely independent:
* `linear-only`: Contains solely the code for Linear and Binary searches.
* `functions-only`: Contains solely the C++ Functions and Pointers practice.
* `topic/sorting-algorithms`: Contains various sorting algorithms like Merge Sort.

---

## 🎯 Progress Tracker
- [x] C++ Basics and Vectors
- [x] Functions and Pointers
- [x] Linear & Binary Search
- [x] Merge Sort Algorithm
- [ ] Recursion Deep Dive
- [ ] Object-Oriented Programming (OOP)
- [ ] Linked Lists Implementation
- [ ] Graphs and Dynamic Programming

<br>
<p align="center">
  <img src="https://github.com/devicons/devicon/blob/master/icons/cplusplus/cplusplus-original.svg" title="C++" alt="C++" width="50" height="50"/>&nbsp;
  <img src="https://github.com/devicons/devicon/blob/master/icons/git/git-original.svg" title="Git" alt="Git" width="50" height="50"/>
</p>
<p align="center"><i>Happy Coding!</i></p>
