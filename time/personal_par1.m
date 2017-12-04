function personal_par1
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.549393 4.241720 3.758210 4.664591 5.740013 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/war.obj 3840x2160');
t1 = [ 3.378031 2.357606 2.003175 2.383242 2.848137 ];
plot(x, t1, 'LineWidth', 3, 'DisplayName', 'models/dragon.obj 3840x2160');
t2 = [ 6.089844 3.920708 3.857329 4.238410 4.967425 ];
plot(x, t2, 'LineWidth', 3, 'DisplayName', 'models/blackdragon.obj 3840x2160');
t3 = [ 5.986538 3.556314 2.706121 2.982083 3.248050 ];
plot(x, t3, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

