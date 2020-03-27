const divide = (arr) => {
    const len = arr.length
    if (len > 1) {
        const mid = Math.floor(len / 2)
        let left = [], right = []
        for (i = 0; i < mid; i++)
            left[i] = arr[i]
        for (i = 0; i < len - mid; i++) 
            right[i] = arr[mid + i]
        console.log(left)
        console.log(right)
        merge(divide(left), divide(right), arr)
    }
}

const merge = (left, right, arr) => {
    let i = j = k = 0
    while (i < left.length && j < right.length) {
        if (left[i] < right[j]) {
            arr[k] = left[i]
            i++
        } else {
            arr[k] = right[j]
            j++
        }
        k++
    }
    while (i < left.length) {
        arr[k] = left[i]
        i++
        k++
    }
    while (j < right.length) {
        arr[k] = right[j]
        j++
        k++
    }
    return arr
}

(() => {
    let unsorted = [2, 4, 1, 6, 8, 5, 3, 7, 11]
    divide(unsorted)
    // setInterval(() => {
    //     console.log(arr)
    // }, 1000)
})()