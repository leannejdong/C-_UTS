class Time
{
public:
	// Constructors and destructor
	Time();		// Default constructor 
	Time(const Time & time);		  // Copy constructor
	/*Time(Time const & time);  // Copy constructor*/
	Time(long secondsAfterMidnight);
	Time(char const* tstring);   // String in hh:mm:ss
				     // format (24 hour time).
	~Time();		          // Destructor
	// Const (read-only) functions
	char*	GetTime(bool military = false) const;
		// Return string representation of the time.
		// 		If military then hh:mm:ss 
		//              else hh:mm:ss am. 
	int	GetHour() const;	// Get hour value.
	int	GetMinute() const;	// Get minute value.
	int	GetSecond() const;	// Get second value.
	bool	operator !() const;     // Returns true if time //     is NOT valid
	//bool    operator !=(const Time& time) const;//This doesn't work..why?????
	bool	IsAM() const;		// Is time AM?
	bool	operator ==(Time const& time) const; // Are times equal?
	Time	operator +(Time const& time) const;  // Add times.
	Time	operator -(Time const& time) const;  // Subtract times.
		// Non-const (read/write) functions
	void   SetTime(int hrs, int mins = 0, int secs = 0);
		// Set the time to the values supplied (in 24 hour format)
	void	AddHours(int hours);		// Add hours (which may be <0).
	void	AddMinutes(int minutes);	// Add minutes (which may be < 0).
	void	AddSeconds(int seconds);	// Add seconds (which may be < 0).
	void	Show() const;
private:
	long sfm;
	static const int SEC_IN_HOUR = 3600;
	static const int SEC_IN_MINUTE = 60;
	int hours;
	int minutes;
	int seconds;
	char *theTime;
	//char *timestring;

};
 
