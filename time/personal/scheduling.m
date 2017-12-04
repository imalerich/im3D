function static1
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.229347 1.274496 0.837284 0.873060 7.448848 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(static, 1)');
t0 = [ 2.259926 1.298466 0.765203 0.784985 7.189409 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(static, 4)');
t0 = [ 2.163130 1.234190 0.776501 0.997283 7.214013 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(static, 8)');

t0 = [ 3.287317 2.210785 1.770884 4.542323 10.010094 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(dynamic, 1)');
t0 = [ 2.396339 1.526432 0.965712 0.907712 6.855692 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(dynamic, 4)');
t0 = [ 2.253108 1.389646 0.881040 0.843262 7.132603 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(dynamic, 8)');

t0 = [ 2.234987 1.355025 0.864444 1.050368 7.717989 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(guided, 1)');
t0 = [ 2.080330 1.285662 0.838019 0.898884 6.761821 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(guided, 4)');
t0 = [ 2.092850 1.261323 0.817261 0.986027 7.041624 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(guided, 8)');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

