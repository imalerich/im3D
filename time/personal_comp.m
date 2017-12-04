function personal_par2
clear all;
close all;
hold on;

x = [1 2 4 8 16];

method0 = [ 5.961468 3.550811 2.639570 2.942769 3.220608 ];
plot(x, method0, 'LineWidth', 3, 'DisplayName', 'Method 1');
method1 = [ 5.986538 3.556314 2.706121 2.982083 3.248050 ];
plot(x, method1, 'LineWidth', 3, 'DisplayName', 'Method 2');
method2 = [ 5.989702 3.455032 2.017855 1.854047 7.986002 ];
plot(x, method2, 'LineWidth', 3, 'DisplayName', 'Method 3');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

