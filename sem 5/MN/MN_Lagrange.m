function [ p, L ] = MN_Lagrange( x, y )
% funckja interpolacji wielominaowej Lagrange'a
% argumenty wejsciowe
    % x , y - punkty
% argumenty wyjsciowe
    % p - wielomian Lagrange
    % L - poszczegolne wielomiany mniejsze
    
n = length(x); % rzad wielomianu + 1

L = zeros(n); 
p = 0; 

	for j = 1:n
		licznik = 1; mianownik = 1; % reset
		for i = 1:n % petla dla poszczegolnych punktow
			if j ~= i % zeby nie bylo dzielenia przez 0
				licznik = conv( licznik, [ 1 -x(i) ] );
				mianownik = mianownik * polyval( [1 -x(i)], x(j) ); 
			end
		end

		L(j, :) = licznik ./ mianownik; 
		p = p + L(j, :) * y(j); 

	end
end

