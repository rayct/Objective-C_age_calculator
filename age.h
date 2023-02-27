// Version: 1.0
// Here's an implementation of the age calculation program in Objective-C:
// This program uses NSDate and NSDateComponents to perform the age and next birthday calculations.
// The input is read from the console using NSFileHandle and NSString. The output is printed to the console using NSLog.

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSString *inputDate;
        NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
        [dateFormat setDateFormat:@"dd/MM/yyyy"];

        NSLog(@"Enter your date of birth (format: DD/MM/YYYY):");
        inputDate = [[NSString alloc] initWithData:[[NSFileHandle fileHandleWithStandardInput] availableData] encoding:NSUTF8StringEncoding];
        inputDate = [inputDate stringByTrimmingCharactersInSet:[NSCharacterSet newlineCharacterSet]];

        NSDate *birthDate = [dateFormat dateFromString:inputDate];
        if (!birthDate) {
            NSLog(@"Invalid date format. Please enter date in the format DD/MM/YYYY.");
            return 0;
        }

        NSDateComponents *ageComponents = [[NSCalendar currentCalendar] components:NSCalendarUnitYear fromDate:birthDate toDate:[NSDate date] options:0];
        NSInteger age = [ageComponents year];
        NSLog(@"You are %ld years old.", age);

        NSDateComponents *nextBirthdayComponents = [[NSCalendar currentCalendar] components:NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear fromDate:[NSDate date]];
        [nextBirthdayComponents setMonth:[birthDate month]];
        [nextBirthdayComponents setDay:[birthDate day]];
        if ([[NSDate date] compare:[nextBirthdayComponents date]] == NSOrderedDescending) {
            [nextBirthdayComponents setYear:[nextBirthdayComponents year] + 1];
        }
        NSDate *nextBirthday = [[NSCalendar currentCalendar] dateFromComponents:nextBirthdayComponents];
        NSDateComponents *daysToBirthdayComponents = [[NSCalendar currentCalendar] components:NSCalendarUnitDay fromDate:[NSDate date] toDate:nextBirthday options:0];
        NSInteger daysToBirthday = [daysToBirthdayComponents day];
        NSLog(@"There are %ld days until your next birthday.", daysToBirthday);
    }
    return 0;
}


