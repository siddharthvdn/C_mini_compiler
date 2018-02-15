float compound_interest(float p, float r, float n)
{
      float interest;
      interest = p*((1 + r/100)^n - 1);
      return interest;
}
 
int main()
{
      float principal, rate_of_interest, time_period, result;
      printf("\nEnter The Principal Amount:\t");
      scanf("%f", &principal);
      printf("\nEnter The Interest Rate:\t");
      scanf("%f", &rate_of_interest);
      printf("\nEnter The Time Period in Years:\t");
      scanf("%f", &time_period);
      result = compound_interest(principal, rate_of_interest, time_period);
      printf("\nCompound Interest:\t%f\n", result);
      return 0;
}
