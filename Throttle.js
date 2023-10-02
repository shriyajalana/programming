function throttle(fn, delay) {
	let flag = true;
	let context = this;
	return function (...args) {
		if (flag) {
			fn.apply(context, args);
			flag = false;
			setTimeout(() => {
				flag = true;
			}, delay);
		}
	};
}
