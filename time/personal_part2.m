function personal_part2
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.129810 1.320217 0.880982 0.747169 1.145696 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/war.obj 3840x2160');
t1 = [ 1.303213 0.797983 0.551378 0.737375 1.092547 ];
plot(x, t1, 'LineWidth', 3, 'DisplayName', 'models/dragon.obj 3840x2160');
t2 = [ 2.321844 1.357127 0.818495 0.796629 1.892450 ];
plot(x, t2, 'LineWidth', 3, 'DisplayName', 'models/blackdragon.obj 3840x2160');
t3 = [ 2.086128 1.262988 0.811297 0.827493 7.475037 ];
plot(x, t3, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

