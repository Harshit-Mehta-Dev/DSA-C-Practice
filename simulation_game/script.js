const container = document.getElementById("bars-container");
const generateBtn = document.getElementById("generate-btn");
const bubbleBtn = document.getElementById("bubble-btn");
const mergeBtn = document.getElementById("merge-btn");
const speedControl = document.getElementById("speed");
const statusText = document.getElementById("status-text");

let bars = [];
let isSorting = false;
let delayTime = 100;

// Update speed dynamically
speedControl.addEventListener("input", (e) => {
    // Reverse the logic so that moving slider to right (max value) is faster
    // Speed slider max is 300, min is 10.
    // If max is 300, delay should be small (e.g. 10ms). If min is 10, delay should be large (300ms).
    delayTime = 310 - parseInt(e.target.value);
});

// Delay helper
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

// Initialize array
function generateArray(size = 40) {
    if (isSorting) return;
    container.innerHTML = "";
    bars = [];
    
    for (let i = 0; i < size; i++) {
        const value = Math.floor(Math.random() * 90) + 10;
        const bar = document.createElement("div");
        bar.classList.add("bar");
        bar.style.height = `${value}%`;
        
        container.appendChild(bar);
        bars.push({ element: bar, value: value });
    }
    statusText.innerText = "New Array Generated";
    statusText.style.color = "var(--bar-default)";
}

// Disable/Enable UI
function toggleUI(disabled) {
    isSorting = disabled;
    generateBtn.disabled = disabled;
    bubbleBtn.disabled = disabled;
    mergeBtn.disabled = disabled;
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
                // Swap heights
                let tempHeight = bars[j].element.style.height;
                bars[j].element.style.height = bars[j+1].element.style.height;
                bars[j+1].element.style.height = tempHeight;
                
                // Swap values
                let tempVal = bars[j].value;
                bars[j].value = bars[j+1].value;
                bars[j+1].value = tempVal;
            }
            
            bars[j].element.style.backgroundColor = "var(--bar-default)";
            bars[j+1].element.style.backgroundColor = "var(--bar-default)";
        }
        // Mark as sorted
        bars[n - i - 1].element.style.backgroundColor = "var(--bar-sorted)";
    }
    bars[0].element.style.backgroundColor = "var(--bar-sorted)";
    
    statusText.innerText = "Bubble Sort Complete!";
    statusText.style.color = "var(--bar-sorted)";
    toggleUI(false);
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
        L[i] = bars[l + i].value;
    }
    for (let j = 0; j < n2; j++) {
        await sleep(delayTime / 2);
        bars[m + 1 + j].element.style.backgroundColor = "var(--bar-compare)";
        R[j] = bars[m + 1 + j].value;
    }
    
    await sleep(delayTime);
    
    let i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            bars[k].value = L[i];
            bars[k].element.style.height = `${L[i]}%`;
            i++;
        } else {
            bars[k].value = R[j];
            bars[k].element.style.height = `${R[j]}%`;
            j++;
        }
        bars[k].element.style.backgroundColor = "var(--bar-sorted)";
        k++;
        await sleep(delayTime);
    }
    
    while (i < n1) {
        bars[k].value = L[i];
        bars[k].element.style.height = `${L[i]}%`;
        bars[k].element.style.backgroundColor = "var(--bar-sorted)";
        i++;
        k++;
        await sleep(delayTime);
    }
    
    while (j < n2) {
        bars[k].value = R[j];
        bars[k].element.style.height = `${R[j]}%`;
        bars[k].element.style.backgroundColor = "var(--bar-sorted)";
        j++;
        k++;
        await sleep(delayTime);
    }
    
    // Reset colors for next steps unless it's the final merge
    for(let i = l; i <= r; i++) {
        bars[i].element.style.backgroundColor = "var(--bar-default)";
    }
}

// Event Listeners
generateBtn.addEventListener("click", () => generateArray());
bubbleBtn.addEventListener("click", bubbleSort);
mergeBtn.addEventListener("click", mergeSortWrapper);

// Start
generateArray();
