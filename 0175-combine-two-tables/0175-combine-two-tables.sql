SELECT P.firstName,P.lastName, A.city, A.state FROM Person P Left Join Address A on P.personId=A.personId;
