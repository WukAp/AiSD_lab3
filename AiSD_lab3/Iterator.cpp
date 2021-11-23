class Iterator {
public:
	//return next node of the graph
	virtual int next() {
		return 0;
	}
	//is the next value exist
	virtual bool has_next() {
	return false;
	}
};