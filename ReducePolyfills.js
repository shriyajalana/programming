Array.prototype.myReduce = function (callback, init) {
	let reduceValue;
	if (init != undefined) reduceValue = init;
	else reduceValue = this[0];
	for (let i = 1; i < this.length; i++) {
		reduceValue = callback(reduceValue, this[i]);
	}
