function method3
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 4.580529 2.832942 1.678800 2.148484 2.665984 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/war.obj 3840x2160');
t1 = [ 2.802862 1.710935 0.983757 1.560008 2.149212 ];
plot(x, t1, 'LineWidth', 3, 'DisplayName', 'models/dragon.obj 3840x2160');
t2 = [ 5.318062 3.169592 1.849405 2.824772 3.846818 ];
plot(x, t2, 'LineWidth', 3, 'DisplayName', 'models/blackdragon.obj 3840x2160');
t3 = [ 5.923093 3.786306 2.412349 6.849016 11.495569 ];
plot(x, t3, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

