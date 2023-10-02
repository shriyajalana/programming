function debounce(fn, delay) {
	let timer;
	const context = this;
	return function (...args) {
		if (timer) {
			clearTimeout(timer);
		}
		timer = setTimeout(() => {
			fn.apply(context, args);
		}, delay);
	};
}
