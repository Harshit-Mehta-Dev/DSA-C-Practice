const container = document.getElementById("bars-container");
const generateBtn = document.getElementById("generate-btn");
const bubbleBtn = document.getElementById("bubble-btn");
const mergeBtn = document.getElementById("merge-btn");
const quickBtn = document.getElementById("quick-btn");
const insertionBtn = document.getElementById("insertion-btn");
const selectionBtn = document.getElementById("selection-btn");
const speedControl = document.getElementById("speed");
const statusText = document.getElementById("status-text");

let bars = [];
let isSorting = false;
let delayTime = 100;

speedControl.addEventListener("input", (e) => {
    delayTime = 310 - parseInt(e.target.value);
    setTransitionSpeed(delayTime);
});

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

function setTransitionSpeed(ms) {
    const seconds = ms / 1000;
    bars.forEach(b => {
        b.element.style.transition = `transform ${seconds}s ease, background-color ${seconds}s ease, height ${seconds}s ease`;
    });
}

function updatePositions() {
    const barWidth = 30;
    const gap = 2;
    const totalWidth = bars.length * barWidth + (bars.length - 1) * gap;
    // Calculate how far from the left we need to be to center everything
    const offset = (container.clientWidth - totalWidth) / 2;
    
    for (let i = 0; i < bars.length; i++) {
        const xPos = offset + i * (barWidth + gap);
        bars[i].element.style.transform = `translateX(${xPos}px)`;
    }
}

// Recalculate on window resize
window.addEventListener("resize", () => {
    if (bars.length > 0) updatePositions();
});

function generateArray(size = 20) {
    if (isSorting) return;
    container.innerHTML = "";
    bars = [];
    
    for (let i = 0; i < size; i++) {
        const value = Math.floor(Math.random() * 90) + 10;
        const bar = document.createElement("div");
        bar.classList.add("bar");
        bar.style.height = `${value}%`;
        bar.innerText = value;
        
        container.appendChild(bar);
        bars.push({ element: bar, value: value });
    }
    
    setTransitionSpeed(delayTime);
    updatePositions();
    
    statusText.innerText = "New Array Generated";
    statusText.style.color = "var(--bar-default)";
}

function toggleUI(disabled) {
    isSorting = disabled;
    generateBtn.disabled = disabled;
    bubbleBtn.disabled = disabled;
    mergeBtn.disabled = disabled;
    quickBtn.disabled = disabled;
    insertionBtn.disabled = disabled;
    selectionBtn.disabled = disabled;
}

// Swaps the objects in the array and animates their physical positions
function swapBars(i, j) {
    let temp = bars[i];
    bars[i] = bars[j];
    bars[j] = temp;
    updatePositions();
}

// --- Bubble Sort ---
async function bubbleSort() {
    toggleUI(true);
    statusText.innerText = "Running Bubble Sort...";
    statusText.style.color = "var(--bar-compare)";

    let n = bars.length;
    for (let i = 0; i < n - 1; i++) {
        for (let j = 0; j < n - i - 1; j++) {
            bars[j].element.style.backgroundColor = "var(--bar-compare)";
            bars[j+1].element.style.backgroundColor = "var(--bar-compare)";
            
            await sleep(delayTime);
            
            if (bars[j].value > bars[j+1].value) {
                swapBars(j, j+1);
                await sleep(delayTime); // Wait for translation animation
            }
            
            bars[j].element.style.backgroundColor = "var(--bar-default)";
            bars[j+1].element.style.backgroundColor = "var(--bar-default)";
        }
        bars[n - i - 1].element.style.backgroundColor = "var(--bar-sorted)";
    }
    bars[0].element.style.backgroundColor = "var(--bar-sorted)";
    
    statusText.innerText = "Bubble Sort Complete!";
    statusText.style.color = "var(--bar-sorted)";
    toggleUI(false);
}

// --- Selection Sort ---
async function selectionSort() {
    toggleUI(true);
    statusText.innerText = "Running Selection Sort...";
    statusText.style.color = "var(--bar-compare)";

    let n = bars.length;
    for (let i = 0; i < n - 1; i++) {
        let min_idx = i;
        bars[i].element.style.backgroundColor = "var(--primary)";
        
        for (let j = i + 1; j < n; j++) {
            bars[j].element.style.backgroundColor = "var(--bar-compare)";
            await sleep(delayTime);
            
            if (bars[j].value < bars[min_idx].value) {
                if (min_idx !== i) {
                    bars[min_idx].element.style.backgroundColor = "var(--bar-default)";
                }
                min_idx = j;
                bars[min_idx].element.style.backgroundColor = "var(--primary)";
            } else {
                bars[j].element.style.backgroundColor = "var(--bar-default)";
            }
        }
        
        if (min_idx !== i) {
            swapBars(i, min_idx);
            await sleep(delayTime);
        }
        
        bars[min_idx].element.style.backgroundColor = "var(--bar-default)";
        bars[i].element.style.backgroundColor = "var(--bar-sorted)";
    }
    bars[n - 1].element.style.backgroundColor = "var(--bar-sorted)";
    
    statusText.innerText = "Selection Sort Complete!";
    statusText.style.color = "var(--bar-sorted)";
    toggleUI(false);
}

// --- Insertion Sort ---
async function insertionSort() {
    toggleUI(true);
    statusText.innerText = "Running Insertion Sort...";
    statusText.style.color = "var(--bar-compare)";

    let n = bars.length;
    bars[0].element.style.backgroundColor = "var(--bar-sorted)";
    
    for (let i = 1; i < n; i++) {
        let j = i;
        bars[i].element.style.backgroundColor = "var(--bar-compare)";
        await sleep(delayTime);
        
        while (j > 0 && bars[j - 1].value > bars[j].value) {
            bars[j].element.style.backgroundColor = "var(--bar-compare)";
            bars[j-1].element.style.backgroundColor = "var(--bar-compare)";
            await sleep(delayTime);
            
            swapBars(j, j - 1);
            await sleep(delayTime);
            
            bars[j].element.style.backgroundColor = "var(--bar-sorted)";
            bars[j-1].element.style.backgroundColor = "var(--bar-compare)";
            j--;
        }
        bars[j].element.style.backgroundColor = "var(--bar-sorted)";
    }
    
    statusText.innerText = "Insertion Sort Complete!";
    statusText.style.color = "var(--bar-sorted)";
    toggleUI(false);
}

// --- Quick Sort ---
async function quickSortWrapper() {
    toggleUI(true);
    statusText.innerText = "Running Quick Sort...";
    statusText.style.color = "var(--bar-compare)";
    
    await quickSort(0, bars.length - 1);
    
    for (let i = 0; i < bars.length; i++) {
        bars[i].element.style.backgroundColor = "var(--bar-sorted)";
    }
    
    statusText.innerText = "Quick Sort Complete!";
    statusText.style.color = "var(--bar-sorted)";
    toggleUI(false);
}

async function quickSort(low, high) {
    if (low < high) {
        let pi = await partition(low, high);
        await quickSort(low, pi - 1);
        await quickSort(pi + 1, high);
    } else if (low === high) {
        bars[low].element.style.backgroundColor = "var(--bar-sorted)";
    }
}

async function partition(low, high) {
    let pivot = bars[high].value;
    bars[high].element.style.backgroundColor = "var(--primary)"; // pivot
    
    let i = (low - 1);
    for (let j = low; j <= high - 1; j++) {
        bars[j].element.style.backgroundColor = "var(--bar-compare)";
        await sleep(delayTime);
        
        if (bars[j].value < pivot) {
            i++;
            swapBars(i, j);
            await sleep(delayTime);
            bars[i].element.style.backgroundColor = "orange";
        } else {
            bars[j].element.style.backgroundColor = "var(--bar-default)";
        }
    }
    
    await sleep(delayTime);
    swapBars(i + 1, high);
    await sleep(delayTime);
    
    bars[high].element.style.backgroundColor = "var(--bar-default)";
    bars[i + 1].element.style.backgroundColor = "var(--bar-sorted)";
    
    for(let k = low; k < i + 1; k++) {
        bars[k].element.style.backgroundColor = "var(--bar-default)";
    }
    
    return (i + 1);
}

// --- Merge Sort ---
async function mergeSortWrapper() {
    toggleUI(true);
    statusText.innerText = "Running Merge Sort...";
    statusText.style.color = "var(--bar-compare)";
    
    await mergeSort(0, bars.length - 1);
    
    for (let i = 0; i < bars.length; i++) {
        bars[i].element.style.backgroundColor = "var(--bar-sorted)";
        await sleep(delayTime / 2);
    }
    
    statusText.innerText = "Merge Sort Complete!";
    statusText.style.color = "var(--bar-sorted)";
    toggleUI(false);
}

async function mergeSort(l, r) {
    if (l >= r) return;
    const m = l + Math.floor((r - l) / 2);
    
    await mergeSort(l, m);
    await mergeSort(m + 1, r);
    await merge(l, m, r);
}

async function merge(l, m, r) {
    let n1 = m - l + 1;
    let n2 = r - m;
    
    let L = new Array(n1);
    let R = new Array(n2);
    
    for (let i = 0; i < n1; i++) {
        await sleep(delayTime / 2);
        bars[l + i].element.style.backgroundColor = "var(--primary)";
        L[i] = bars[l + i];
    }
    for (let j = 0; j < n2; j++) {
        await sleep(delayTime / 2);
        bars[m + 1 + j].element.style.backgroundColor = "var(--bar-compare)";
        R[j] = bars[m + 1 + j];
    }
    
    await sleep(delayTime);
    
    let i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i].value <= R[j].value) {
            bars[k] = L[i];
            i++;
        } else {
            bars[k] = R[j];
            j++;
        }
        bars[k].element.style.backgroundColor = "var(--bar-sorted)";
        updatePositions();
        k++;
        await sleep(delayTime);
    }
    
    while (i < n1) {
        bars[k] = L[i];
        bars[k].element.style.backgroundColor = "var(--bar-sorted)";
        updatePositions();
        i++;
        k++;
        await sleep(delayTime);
    }
    
    while (j < n2) {
        bars[k] = R[j];
        bars[k].element.style.backgroundColor = "var(--bar-sorted)";
        updatePositions();
        j++;
        k++;
        await sleep(delayTime);
    }
    
    for(let idx = l; idx <= r; idx++) {
        bars[idx].element.style.backgroundColor = "var(--bar-default)";
    }
}

// Event Listeners
generateBtn.addEventListener("click", () => generateArray());
bubbleBtn.addEventListener("click", bubbleSort);
selectionBtn.addEventListener("click", selectionSort);
insertionBtn.addEventListener("click", insertionSort);
quickBtn.addEventListener("click", quickSortWrapper);
mergeBtn.addEventListener("click", mergeSortWrapper);

// Start
generateArray();
