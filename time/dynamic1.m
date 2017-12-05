function dynamic1
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 7.176597 4.249530 3.100026 2.932752 2.823958 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

