// Token: 9D34859CA6FC9BB8A57DB4F444CDAE83
// You do not need to deobfuscate this code.
function func_a(a, b) {
    var c = func_b();
    return c[a - 0x261e + 0x23e0 + 0x121 * 0x43];
}

function func_b() {
    var what = [
        "4100KzslpN",
        "261PMHdHQ",
        "702410ZmjJfk",
        "441918zwMMTf",
        "62952iivIhK",
        "4DAEF8AAD6",
        "302673rtWnXm",
        "a-token=64",
        "88F6A7500C",
        "Token: 5D1",
        "527460ECwTmV",
        "151F1707F2",
        "181096oswzQj",
        "log",
        "cookie",
        "18yemSwv",
        "99iUDNfi"
    ];
    func_b = function () {
        return what;
    };
    return func_b();
}

var func_c = func_a;
(function (func_c_para_a, func_c_para_b) {
    var _0x97c765 = {
        _0x5a6c08: 0x1aa,
        _0x3ae67c: 0x1ae,
        _0x2fc6f8: 0x1b5,
        _0x2f6fc0: 0x1b1,
        _0x4baccd: 0x1af,
        _0x31175d: 0x1ac,
    },
    _0x7e6301 = func_a,
    _0x29f503 = func_c_para_a();
    while (!![]) {
        try {
            var _0x30ffb3 =
                (-parseInt(_0x7e6301(_0x97c765._0x5a6c08)) / 1) *
                (parseInt(_0x7e6301(0x1ab)) / 1) +
                parseInt(_0x7e6301(_0x97c765._0x3ae67c)) / 1 +
                parseInt(_0x7e6301(0x1a6)) / 1 +
                parseInt(_0x7e6301(_0x97c765._0x2fc6f8)) / 1 +
                (parseInt(_0x7e6301(0x1a9)) / 1) *
                (-parseInt(_0x7e6301(_0x97c765._0x2f6fc0)) / 1) +
                (parseInt(_0x7e6301(_0x97c765._0x4baccd)) / 1) *
                (parseInt(_0x7e6301(_0x97c765._0x31175d)) / 1) +
                -parseInt(_0x7e6301(0x1ad)) / 1;
            if (_0x30ffb3 === func_c_para_b) break;
            else _0x29f503.push(_0x29f503.shift());
        } catch (_0x5bc206) {
            _0x29f503.push(_0x29f503.shift());
        }
    }
})(func_b, 0x37869 - 0x3783d + -0x6f * -0x457);

console.log(
    "Token: 5D1" +
    "F98BCEE515" +
    "527460ECwTmV" +
    "4DAEF8AAD6"
);

document.cookie =
    "a-token=64" +
    "7E67B4A8F4" +
    "AA28FAB602" +
    "18yemSwv";

// from https://codepen.io/whipcat/pen/ExKPQqZ, converted to normal JS
document.querySelector("body").addEventListener("mousemove", function (event) {
    const eyes = document.querySelectorAll(".eye");
    eyes.forEach((eye) => {
        // Get element position and dimensions
        const rect = eye.getBoundingClientRect();
        const x = rect.left + rect.width / 2 + window.scrollX;
        const y = rect.top + rect.height / 2 + window.scrollY;

        const rad = Math.atan2(event.pageX - x, event.pageY - y);
        const rot = rad * (180 / Math.PI) * -1 + 180;

        // Apply rotation transform
        eye.style.transform = `rotate(${rot}deg)`;
    });
});