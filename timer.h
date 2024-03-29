#include <time.h>

using namespace std;

class timer {
	private:
		unsigned long begTime;
	public:
		void start() {
			begTime = clock();
      cout << "timer started . . ." << endl;
		}

		unsigned long elapsedTime() {
			return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
		}

		bool isTimeout(unsigned long seconds) {
			return seconds >= elapsedTime();
		}
};
