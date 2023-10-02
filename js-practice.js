let obj = {
	name: 'afroz',
	age: 23
};

let arrObj = [
	{ id: 1, name: 'afroz' },
	{ id: 2, name: 'amit' },
	{ id: 3, name: 'dk' },
	{ id: 4, name: 'hritik' }
];

let arr = [1, 2, 3, 4, 15];

let arr2 = arr.slice(0, 3);

console.log(arr, arr2);

let x = arrObj.find(item => item.id == 4);
x.name = 'dell wala';

console.log('12345'.split('').indexOf(''));

Array.prototype.myReduce = function (callback, init) {
	let reduceValue;
	if (init != undefined) reduceValue = init;
	else reduceValue = this[0];
	for (let i = 1; i < this.length; i++) {
		reduceValue = callback(reduceValue, this[i]);
	}

	return reduceValue;
};
let sum = arr.reduce((acc, num) => {
	console.log(acc, num);
	return acc + num;
}, 10);

let sum = arr.reduce((acc, num) => {
	console.log(acc, num);
	return acc + num;
});
console.log(sum);

const sentence = 'I am learning JavaScript and JavaScript is fun.';

let x = sentence.split(' ').reduce((acc, curr) => {
	acc[curr] ? acc[curr]++ : (acc[curr] = 1);
	return acc;
}, {});

console.log(x);
