function sample
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.143361 1.338548 0.797491 0.995768 1.222356 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/war.obj 3840x2160');
t1 = [ 1.288743 0.812967 0.521641 0.814768 1.606599 ];
plot(x, t1, 'LineWidth', 3, 'DisplayName', 'models/dragon.obj 3840x2160');
t2 = [ 2.241275 1.481919 0.906093 2.231677 2.128020 ];
plot(x, t2, 'LineWidth', 3, 'DisplayName', 'models/blackdragon.obj 3840x2160');
t3 = [ 2.126725 1.268309 0.813295 0.864115 7.227923 ];
plot(x, t3, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

