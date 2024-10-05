# Investment App Overview

## Main Steps
1. **Display Menu**
2. **Accept Inputs** (One per line & Validate each):
   - Initial Investment `<double>`
   - Monthly Deposit `<double>`
   - Annual Interest `<double>`
   - Number of Years `<int>`
3. **Calculate** the number of months based on the number of years
4. **Initialize** variables for tracking balances and interest
5. **Initialize** a list to store yearly results
6. **Loop through each month** to calculate:
   - **Opening Amount**: Initial Investment for the first month, then previous month's closing balance
   - **Deposited Amount**: Monthly Deposit
   - **Total**: Opening Amount + Deposited Amount
   - **Interest**: `(Total * (Annual Interest / 100) / 12)`
   - **Update Closing Balance**: Total + Interest
   - At the end of each year, store the yearly results
7. **Display yearly results**
8. **Accept input** to change values and repeat or exit

## Classes

### Investment Class

#### Attributes:
- `initial_investment`: The starting amount of the investment.
- `monthly_deposit`: The amount deposited each month.
- `annual_interest`: The annual interest rate.
- `years`: The number of years for the investment.
- `yearly_results`: A list to store the results for each year.

#### Methods:
- **Initialize Attributes**: Set the initial investment, monthly deposit, annual interest, and years.
- **Calculate Yearly Results**:
  - Calculate the number of months based on the number of years.
  - Initialize the opening amount and other necessary variables.
  - Loop through each month to calculate:
    - Opening Amount: Initial Investment for the first month, then previous month's closing balance.
    - Deposited Amount: Monthly Deposit.
    - Total: Opening Amount + Deposited Amount.
    - Interest: `(Total * (Annual Interest / 100) / 12)`
    - Update Closing Balance: Total + Interest.
    - At the end of each year, store the yearly results.
- **Get Yearly Results**: Return the yearly results.

### InvestmentApp Class

#### Attributes:
- `investment`: An instance of the Investment class.

#### Methods:
- **Display Menu**: Show the menu options to the user.
- **Get User Input**:
  - Prompt the user for initial investment, monthly deposit, annual interest rate, and number of years.
  - Validate each input.
  - Create an instance of the Investment class with the user inputs.
- **Display Yearly Results**: Show the yearly results stored in the Investment instance.
- **Run**:
  - Main loop to run the application.
  - Display the menu.
  - Get user input.
  - Calculate yearly results.
  - Display yearly results.
  - Allow the user to repeat or exit.
