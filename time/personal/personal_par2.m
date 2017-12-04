function personal_par2
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.496629 3.385634 2.012052 1.752530 2.165488 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/war.obj 3840x2160');
t1 = [ 3.369382 2.022792 1.247250 1.213758 1.713614 ];
plot(x, t1, 'LineWidth', 3, 'DisplayName', 'models/dragon.obj 3840x2160');
t2 = [ 5.957349 3.546410 2.090667 1.778129 3.005112 ];
plot(x, t2, 'LineWidth', 3, 'DisplayName', 'models/blackdragon.obj 3840x2160');
t3 = [ 5.989702 3.455032 2.017855 1.854047 7.986002 ];
plot(x, t3, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

