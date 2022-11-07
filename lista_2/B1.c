int faz_conta_direito(int p, char op) {
	int acc = 0;
	for (int i = 0; i < p; i++) {
		int n = 0;
		scanf("%d", &n);
		if (op == '+') {
			acc += n;
		} else if (op == '-' && i == 0) {
			acc = n;
		} else if (op == '-' && i > 0) {
			acc -= n;
		}
	}
	return acc;
}
