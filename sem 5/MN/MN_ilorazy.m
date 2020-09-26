function [ p, C ] = MN_ilorazy( x ,y )
% funckja interpolacji metoda roznic wielomianowych
% argumenty wejsciowe
    % x , y - punkty
% argumenty wyjsciowe
    % p - wielomian interpolacyjny
    
    n = length(x) - 1;
    m = n;
    C = zeros(n); % tablica ilorazow roznicowych
    r = 1; % roznica odleglosci miedzy x
    
    for j = 1:n % kolejny rzad roznic
        if j == 1 % dla pierwszego rzedu
            for i = 1:m 
                C(i, j) = ( y(i+1) - y(i) ) / ( x(i+r) - x(i) );
            end
        elseif j > 1
            for i = 1:m 
                C(i, j) = ( C(i+1, j-1) - C(i, j-1) ) / ( x(i+r) - x(i) );
            end
        end
        
        m = m -1; % zmniejszenie ilosci wyrazow o 1
        r = r + 1; % zwiekszenie odleglosci o 1
    end
    
    %% tworzenie wielominau iterpolacyjnego
    f = 1;
    p = y(1);
    
    for i = 1:n
        p = [zeros(1), p]; % wstawienie 0 na poczatku wielominau
        f = conv(f,  [1 -x(i)] ); % mnozenie nawiasow
        p =  p + C(1,i) .* f; % mnozenie przez iloraz i dodawanie
    end
    
end
%     p = y(1) ...
%         + C(1,1) * ( [1 -x(1)] ) ...
%         + C(1,2) * ( [1 -x(1)] ) * ( [1 -x(2)] ) ...
%         + C(1,3) * ( [1 -x(1)] ) * ( [1 -x(2)] ) * ( [1 -x(3)] ) ...
%         + C(1,4) * ( [1 -x(1)] ) * ( [1 -x(2)] ) * ( [1 -x(3)] ) * ( [1 -x(4)] );
    


