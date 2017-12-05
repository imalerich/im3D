function method3
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 4.645203 2.830010 1.681444 1.071299 1.405676 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/war.obj 3840x2160');
t1 = [ 2.804628 1.745820 0.995675 0.640517 1.271734 ];
plot(x, t1, 'LineWidth', 3, 'DisplayName', 'models/dragon.obj 3840x2160');
t2 = [ 5.361165 3.172302 1.845384 1.207566 2.361637 ];
plot(x, t2, 'LineWidth', 3, 'DisplayName', 'models/blackdragon.obj 3840x2160');
t3 = [ 5.920603 3.822494 2.392139 1.916893 8.399670 ];
plot(x, t3, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

