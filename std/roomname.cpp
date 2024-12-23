#include "stdafx.h"
#include "../server/Channel.h"

char global_room_name[MAX_ROOM_NUM][40] = {
"白驼山草丛1",
"白驼山草丛2",
"白驼山草坪",
"白驼山草莓地",
"白驼山柴房",
"白驼山长廊",
"白驼山厨房",
"白驼山储藏室",
"白驼山打铁铺",
"白驼山大门",
"白驼山大厅",
"白驼山东街",
"白驼山洞口",
"白驼山洞内",
"白驼山坟地",
"白驼山戈壁",
"白驼山广场",
"白驼山后院",
"白驼山花园",
"白驼山酒店",
"白驼山练功场",
"白驼山练功房",
"白驼山门廊",
"白驼山内室",
"白驼山农舍",
"白驼山山路",
"白驼山山路1",
"白驼山蛇园",
"白驼山石阶",
"白驼山兽舍",
"白驼山树林",
"白驼山兔苑",
"白驼山武器库",
"白驼山西街",
"白驼山西门",
"白驼山小路1",
"白驼山小路2",
"白驼山小路3",
"白驼山小路4",
"白驼山小桥",
"白驼山休息室",
"白驼山岩洞",
"白驼山药房",
"白驼山院子",
"白驼山竹林",
"白驼山竹园",
"北京长安戏院",
"北京打铁铺",
"北京大驿道1",
"北京大驿道2",
"北京大驿道3",
"北京大驿道4",
"北京大驿道5",
"北京大驿道6",
"北京大驿道7",
"北京大驿道8",
"北京大驿道9",
"北京当铺",
"北京东北",
"北京东厂大门",
"北京东南",
"北京赌场",
"北京高升茶馆",
"北京棺材店",
"北京皇城",
"北京回春堂药店",
"北京康府",
"北京客店1",
"北京客店2",
"北京面馆",
"北京钱庄",
"北京全聚德酒楼",
"北京汝州城",
"北京书院",
"北京塘沽口",
"北京屠宰场",
"北京文庙",
"北京西北",
"北京西厂大门",
"北京西南",
"北京杂货铺",
"北京怡红院",
"北京怡红院二楼",
"北京鳌府",
"长安",
"长安大官道2",
"长安大官道4",
"长安斗鸡房",
"长安拱猪房",
"长安骨骰房",
"长安关洛道",
"长安函谷关",
"长安聚义厅",
"长安乐坊",
"长安乐坊二楼大厅",
"长安乐府诗社",
"长安入神坐照室",
"长安赛龟房",
"长安三楼拱猪房",
"长安相记钱庄",
"长安押签房",
"长安骰子房",
"成都兵器铺",
"成都东",
"成都东府河桥",
"成都杜甫草堂",
"成都府河桥",
"成都济世堂药店",
"成都金牛武馆",
"成都锦城驿",
"成都锦城驿二楼",
"成都南河桥",
"成都蜀都酒楼",
"成都提督府",
"成都望江楼",
"成都武侯祠大门",
"成都西",
"成都溪岸小路",
"成都中",
"大理城阿头部",
"大理城巴的甸",
"大理城半山竹林",
"大理城北门",
"大理城碧鸡山顶",
"大理城碧罗山下",
"大理城碧罗雪山",
"大理城兵营",
"大理城步雄部",
"大理城苍山",
"大理城苍山山路",
"大理城苍山中部",
"大理城茶花山1",
"大理城茶花山2",
"大理城茶花山3",
"大理城茶花山4",
"大理城茶花山5",
"大理城茶花山南",
"大理城长湖",
"大理城川西山路",
"大理城村外草坡",
"大理城大叠水瀑布",
"大理城大渡河边",
"大理城大杆栏",
"大理城大路4",
"大理城大竹楼",
"大理城滇池",
"大理城滇池沿岸1",
"大理城东",
"大理城东泸水河谷",
"大理城洱水桥",
"大理城杆栏",
"大理城杆栏3",
"大理城高黎山东坡",
"大理城高黎山密林",
"大理城葛鲁城",
"大理城古道",
"大理城官道1",
"大理城官道2",
"大理城官道3",
"大理城和摩赛石林",
"大理城河边",
"大理城河上",
"大理城河西镇",
"大理城黑龙岭",
"大理城宏圣寺塔",
"大理城蝴蝶泉",
"大理城黄土路",
"大理城皇宫偏殿",
"大理城皇宫前殿",
"大理城皇宫御膳坊",
"大理城皇宫正殿",
"大理城祭祀大屋",
"大理城剑川山口",
"大理城剑川镇",
"大理城金汁河畔",
"大理城经幢1",
"大理城经幢2",
"大理城经幢3",
"大理城经幢4",
"大理城经幢5",
"大理城经幢6",
"大理城经幢7",
"大理城客店",
"大理城李子箐石林",
"大理城林间小道1",
"大理城林间小道2",
"大理城林中山涧",
"大理城龙口城",
"大理城鲁望镇",
"大理城路南石林",
"大理城绿玉溪沿岸",
"大理城罗伽甸",
"大理城马厩",
"大理城密林",
"大理城南门",
"大理城南五华楼",
"大理城南五华楼二楼",
"大理城南诏德化碑",
"大理城拈花寺",
"大理城农田",
"大理城农田2",
"大理城农田3",
"大理城农田4",
"大理城农田5",
"大理城青竹林",
"大理城清溪三潭",
"大理城桑林",
"大理城山林",
"大理城山路2",
"大理城山路3",
"大理城山路4",
"大理城山路5",
"大理城山路6",
"大理城山路7",
"大理城山路8",
"大理城山区小径",
"大理城石铺",
"大理城树林外",
"大理城双鹤桥",
"大理城水田",
"大理城太和城",
"大理城太和居",
"大理城太和居二楼",
"大理城梯田",
"大理城天威径",
"大理城王府兵器房",
"大理城王府厨房",
"大理城王府大厅",
"大理城王府内厅",
"大理城王府书房",
"大理城王府司空堂",
"大理城王府司马堂",
"大理城王府司徒堂",
"大理城王府下人居室",
"大理城王府帐房",
"大理城王府总理处",
"大理城乌蒙村落",
"大理城乌弄城",
"大理城乌夷民居",
"大理城乌夷民居1",
"大理城乌夷民居2",
"大理城乌夷民居4",
"大理城武定镇",
"大理城西",
"大理城喜州城",
"大理城下关城",
"大理城星云湖畔",
"大理城薛记成衣铺",
"大理城沿池堤岸1",
"大理城沿池堤岸2",
"大理城沿池堤岸3",
"大理城沿池小路2",
"大理城阳宗镇",
"大理城养蚕房",
"大理城药铺",
"大理城易溪部",
"大理城渔家",
"大理城玉霞山",
"大理城玉虚观",
"大理城玉虚观前",
"大理城镇雄",
"大理城芝云洞",
"大理城竹林深处",
"大理城竹林小路",
"大理城竹楼下",
"大理城泸水沿岸",
"大理城妃丽湖东",
"大理城妃丽湖南岸",
"大理城妃丽湖畔",
"大理城榕树雨林",
"峨嵋八十四盘1",
"峨嵋八十四盘2",
"峨嵋八十四盘3",
"峨嵋白龙洞",
"峨嵋报国寺",
"峨嵋报国寺山门",
"峨嵋纯阳殿",
"峨嵋睹光台",
"峨嵋伏虎寺",
"峨嵋福寿庵",
"峨嵋观音堂",
"峨嵋归云阁",
"峨嵋黑龙江栈道",
"峨嵋华藏庵",
"峨嵋华藏庵大雄宝殿",
"峨嵋华藏庵东侧殿",
"峨嵋华藏庵东廊1",
"峨嵋华藏庵东廊2",
"峨嵋华藏庵广场",
"峨嵋华藏庵后殿",
"峨嵋华藏庵西侧殿",
"峨嵋华藏庵西廊1",
"峨嵋华藏庵西廊2",
"峨嵋华藏庵斋堂",
"峨嵋华藏庵正殿",
"峨嵋华藏庵禅房",
"峨嵋华严顶",
"峨嵋接引殿",
"峨嵋解脱坡",
"峨嵋金顶",
"峨嵋九老洞口",
"峨嵋九十九道拐1",
"峨嵋九十九道拐2",
"峨嵋九十九道拐3",
"峨嵋九十九道拐4",
"峨嵋雷洞坪",
"峨嵋莲花石",
"峨嵋凌云梯",
"峨嵋灵文阁",
"峨嵋密林1",
"峨嵋密林2",
"峨嵋千佛庵",
"峨嵋青石阶",
"峨嵋清音阁",
"峨嵋神水庵",
"峨嵋十二盘1",
"峨嵋十二盘2",
"峨嵋十二盘3",
"峨嵋十二盘4",
"峨嵋万年庵",
"峨嵋万行庵",
"峨嵋卧云庵",
"峨嵋洗象池",
"峨嵋小路",
"峨嵋玉女峰",
"峨嵋中峰寺",
"峨嵋钻天坡1",
"峨嵋钻天坡2",
"佛山",
"佛山北帝庙",
"佛山北门",
"佛山东门",
"佛山林间道1",
"佛山林间道10",
"佛山林间道11",
"佛山林间道12",
"佛山林间道13",
"佛山林间道14",
"佛山林间道2",
"佛山林间道3",
"佛山林间道4",
"佛山林间道5",
"佛山林间道6",
"佛山林间道7",
"佛山林间道8",
"佛山林间道9",
"佛山南岭山口",
"佛山南门",
"佛山烧饼油条铺",
"佛山西门",
"佛山英雄典当",
"佛山英雄会馆",
"佛山英雄楼",
"佛山英雄楼二楼",
"福州东",
"福州福威镖局后院",
"福州福威镖局内宅",
"福州福威镖局正厅",
"福州闽中大道",
"福州南",
"福州南门",
"福州提督衙门",
"福州味中味",
"福州无相庵",
"福州西",
"福州西禅寺",
"福州向阳老宅",
"福州校场",
"福州涌泉寺",
"福州杂货铺",
"福州榕城驿",
"福州榕城驿二楼",
"古墓草地",
"古墓草地2",
"古墓蜂屋",
"古墓寒水潭",
"古墓后厅",
"古墓黄沙岭",
"古墓空地",
"古墓练功室",
"古墓墓门",
"古墓前厅",
"古墓山路",
"古墓树林1",
"古墓树林2",
"古墓孙婆婆小屋",
"古墓小厅",
"古墓小屋",
"古墓休息室",
"古墓正厅",
"古墓终南山主峰",
"关外白河",
"关外白头山天池1",
"关外白头山天池2",
"关外白云峰",
"关外冰面",
"关外长白瀑布",
"关外船厂",
"关外达门",
"关外大门坎子",
"关外二门坎子",
"关外谷草垛",
"关外官道",
"关外黑风口",
"关外华盖峰",
"关外荒路1",
"关外荒路2",
"关外老龙头",
"关外龙门峰",
"关外鹿鸣峰",
"关外满天星",
"关外密林1",
"关外密林2",
"关外宁远",
"关外宁远马厩",
"关外宁远土窑馆",
"关外宁远香肉馆",
"关外宁远小土屋",
"关外山海关",
"关外山神庙",
"关外梯云峰",
"关外天豁峰",
"关外小天池",
"关外雪地1",
"关外雪地2",
"关外雪地3",
"关外玉柱峰",
"归云庄",
"归云庄厨房",
"归云庄练功房",
"归云庄男厢房",
"归云庄女厢房",
"归云庄书房",
"杭州白堤",
"杭州保淑塔",
"杭州宝石山",
"杭州翠微亭",
"杭州大路1",
"杭州大雄宝殿1",
"杭州断桥",
"杭州法镜寺",
"杭州法净寺",
"杭州法喜寺",
"杭州放鹤亭",
"杭州飞来峰",
"杭州凤池书院",
"杭州孤山",
"杭州孤山平台",
"杭州郭庄",
"杭州洪春桥",
"杭州红娘庄",
"杭州胡庆余堂",
"杭州虎跑泉",
"杭州花港观鱼",
"杭州黄龙洞",
"杭州黄泥岭",
"杭州净慈寺",
"杭州聚景园",
"杭州灵隐寺",
"杭州刘庄",
"杭州柳浪桥",
"杭州六和塔",
"杭州龙井",
"杭州龙泓洞",
"杭州楼外楼",
"杭州楼外楼二楼",
"杭州满觉陇",
"杭州茅家埠",
"杭州平湖秋月",
"杭州钱塘江畔",
"杭州青石大道1",
"杭州青石大道10",
"杭州青石大道11",
"杭州青石大道12",
"杭州青石大道13",
"杭州青石大道14",
"杭州青石大道15",
"杭州青石大道16",
"杭州青石大道17",
"杭州青石大道18",
"杭州青石大道19",
"杭州青石大道2",
"杭州青石大道20",
"杭州青石大道3",
"杭州青石大道4",
"杭州青石大道5",
"杭州青石大道6",
"杭州青石大道7",
"杭州青石大道8",
"杭州青石大道9",
"杭州清波门",
"杭州清林洞",
"杭州曲院风荷",
"杭州山路1",
"杭州山路2",
"杭州山路3",
"杭州山路4",
"杭州山路5",
"杭州山路6",
"杭州山路7",
"杭州山路8",
"杭州射旭洞",
"杭州石屋洞",
"杭州水乐洞",
"杭州苏堤1",
"杭州苏堤2",
"杭州苏堤3",
"杭州苏堤4",
"杭州苏堤5",
"杭州苏堤6",
"杭州苏堤7",
"杭州天外天客店",
"杭州天外天客店二楼",
"杭州天王殿",
"杭州铁匠铺",
"杭州土路",
"杭州西泠桥",
"杭州夕照山",
"杭州烟霞洞",
"杭州沿湖大道1",
"杭州沿湖大道2",
"杭州沿湖大道3",
"杭州玉皇山",
"杭州玉皇山顶",
"杭州玉皇山脚",
"杭州玉泉",
"杭州岳坟",
"杭州岳廊",
"黑木崖白虎堂",
"黑木崖白虎堂大厅",
"黑木崖草地",
"黑木崖长廊",
"黑木崖长廊2",
"黑木崖长滩",
"黑木崖成德殿",
"黑木崖厨房",
"黑木崖风雷堂",
"黑木崖风雷堂厨房",
"黑木崖风雷堂大厅",
"黑木崖后厅",
"黑木崖黄土路2",
"黑木崖黄土路3",
"黑木崖黄土路4",
"黑木崖林间小道",
"黑木崖令牌堂",
"黑木崖龙门渡口",
"黑木崖乱石坡",
"黑木崖内室",
"黑木崖平定州",
"黑木崖青龙堂",
"黑木崖青龙堂大厅",
"黑木崖日月坪",
"黑木崖山道",
"黑木崖山谷",
"黑木崖圣姑堂",
"黑木崖石道1",
"黑木崖石道2",
"黑木崖石阶",
"黑木崖石门",
"黑木崖小花园",
"黑木崖小舍",
"黑木崖小舍内室",
"黑木崖猩猩滩",
"黑木崖休息室",
"衡山半山亭",
"衡山藏经殿",
"衡山赤帝峰",
"衡山大殿",
"衡山登高台",
"衡山方广寺",
"衡山福严寺",
"衡山黑沙潭",
"衡山后殿",
"衡山黄土路",
"衡山极高明台",
"衡山嘉应门",
"衡山奎星阁",
"衡山流云坪",
"衡山磨镜台",
"衡山南台寺",
"衡山南天门",
"衡山三生塔",
"衡山山涧",
"衡山山路1",
"衡山山路10",
"衡山山路11",
"衡山山路12",
"衡山山路13",
"衡山山路14",
"衡山山路2",
"衡山山路3",
"衡山山路4",
"衡山山路5",
"衡山山路6",
"衡山山路7",
"衡山山路8",
"衡山山路9",
"衡山狮子岩",
"衡山梳妆台",
"衡山水帘洞",
"衡山天柱峰",
"衡山望日台",
"衡山望月台",
"衡山御碑亭",
"衡山御书楼",
"衡山正北门",
"衡山正川门",
"衡山钟亭",
"衡山祝融殿",
"衡山祝融峰",
"衡山棂星门",
"衡阳茶馆",
"衡阳城",
"衡阳回雁楼",
"衡阳刘府大院",
"衡阳小店",
"恒山白云庵",
"恒山北岳庙",
"恒山翠屏谷1",
"恒山翠屏谷2",
"恒山翠屏山道1",
"恒山翠屏山道2",
"恒山大字岭",
"恒山果老岭",
"恒山虎风口",
"恒山见性峰广场",
"恒山见性峰山道1",
"恒山见性峰山道2",
"恒山金龙峡",
"恒山三教殿",
"恒山梯式栈道",
"恒山通元谷",
"恒山悬空寺",
"恒山云阁虹桥",
"华山百尺峡",
"华山兵器房",
"华山苍龙岭",
"华山长空栈道",
"华山长廊",
"华山朝阳峰",
"华山朝阳峰小路1",
"华山朝阳峰小路2",
"华山沉香劈山处",
"华山厨房",
"华山村",
"华山村草棚",
"华山村民房",
"华山村民宅",
"华山村青石大道",
"华山村铁匠铺",
"华山村玄坛庙",
"华山村杂货店",
"华山后院",
"华山花园",
"华山回心石",
"华山假山小池",
"华山脚下",
"华山金锁关",
"华山居室",
"华山老君沟",
"华山莲花峰",
"华山莲花峰小路",
"华山练武场",
"华山落雁峰",
"华山偏厅",
"华山平心石",
"华山千尺幢",
"华山寝室",
"华山青柯坪",
"华山群仙观",
"华山莎萝坪",
"华山山顶小店",
"华山山洞",
"华山山洪瀑布",
"华山上天梯",
"华山舍身崖",
"华山书房",
"华山思过崖",
"华山松树林",
"华山小山路",
"华山小筑",
"华山有所不为轩",
"华山玉女峰",
"华山玉女峰山路",
"华山玉女祠",
"华山玉泉院",
"华山云门",
"华山云台峰",
"华山镇岳宫",
"华山紫气台",
"华山猢狲愁",
"黄河",
"黄河1",
"黄河2",
"黄河3",
"黄河岸边1",
"黄河岸边2",
"黄河岸边3",
"黄河岸边4",
"黄河岸边5",
"黄河岸边6",
"黄河岸边7",
"黄河帮寨门",
"黄河冰草湾",
"黄河打柴沟",
"黄河古长城",
"黄河古浪",
"黄河广场",
"黄河河套",
"黄河红山峡",
"黄河黄土高原",
"黄河靖远",
"黄河客店",
"黄河马厩",
"黄河皮货药材店",
"黄河青城",
"黄河入海口",
"黄河沙漠1",
"黄河沙漠2",
"黄河沙土路",
"黄河石洞",
"黄河石门",
"黄河石峡子",
"黄河树林1",
"黄河树林2",
"黄河树林3",
"黄河树林4",
"黄河树林5",
"黄河树林6",
"黄河田地1",
"黄河田地2",
"黄河田地3",
"黄河田地4",
"黄河土门子",
"黄河渭汾流域",
"黄河乌鞘岭",
"黄河武威",
"黄河五佛寺",
"黄河侠义厅",
"黄河萧家桥",
"黄河学馆",
"黄河营盘水",
"黄河永登",
"嘉兴城",
"嘉兴南湖",
"嘉兴南门",
"嘉兴铁枪庙",
"嘉兴烟雨楼",
"灵州八仙道观",
"灵州车马店",
"灵州赤陵",
"灵州大将军府",
"灵州刀店",
"灵州德陵",
"灵州东",
"灵州恭陵",
"灵州黄羊滩",
"灵州皇宫大门",
"灵州接引堂",
"灵州酒馆",
"灵州林中大路1",
"灵州林中大屋",
"灵州林中空地",
"灵州林中土路",
"灵州林中小路1",
"灵州林中小路2",
"灵州林中小路3",
"灵州落日林1",
"灵州落日林2",
"灵州马厩",
"灵州鸣沙洲",
"灵州青铜峡",
"灵州清新泉",
"灵州西",
"灵州西夏王陵",
"灵州小坝",
"灵州宣和堡",
"灵州衙门",
"灵州一品堂大厅",
"灵州一品堂帐房",
"灵州骠骑营",
"灵鹫百丈涧",
"灵鹫闭关室",
"灵鹫闭关室大门",
"灵鹫独尊厅",
"灵鹫独尊厅大门",
"灵鹫断魂崖",
"灵鹫花园",
"灵鹫画廊1",
"灵鹫画廊10",
"灵鹫画廊11",
"灵鹫画廊12",
"灵鹫画廊13",
"灵鹫画廊14",
"灵鹫画廊15",
"灵鹫画廊2",
"灵鹫画廊3",
"灵鹫画廊4",
"灵鹫画廊5",
"灵鹫画廊6",
"灵鹫画廊7",
"灵鹫画廊8",
"灵鹫画廊9",
"灵鹫藕香榭",
"灵鹫青石大道1",
"灵鹫青石大道2",
"灵鹫囚室大门",
"灵鹫失足岩",
"灵鹫书房大门",
"灵鹫戏凤阁",
"灵鹫仙愁门",
"灵鹫小道1",
"灵鹫小道2",
"灵鹫玄冰室",
"灵鹫缀锦阁",
"灵鹫蓼风轩",
"灵鹫潇湘馆",
"灵鹫缥缈峰山脚",
"灵鹫憩凤阁",
"梅庄百木园",
"梅庄厨房",
"梅庄大门",
"梅庄大天井",
"梅庄孤山石级",
"梅庄画室",
"梅庄内院",
"梅庄偏房",
"梅庄棋室",
"梅庄奇槐坡",
"梅庄琴音小院",
"梅庄书室",
"梅庄四雅清风",
"梅庄小路",
"梅庄小屋",
"梅庄休息室",
"梅庄迎客亭",
"梅庄走廊1",
"梅庄走廊2",
"梅庄蜿蜒小径",
"明教大殿",
"明教道家竹舍",
"明教地门女舍",
"明教饭堂",
"明教广场",
"明教洪水旗大厅",
"明教厚土旗大厅",
"明教巨木旗大厅",
"明教昆仑山下",
"明教雷门宿舍",
"明教烈火旗大厅",
"明教烈火旗牌坊",
"明教青石大道1",
"明教青石大道2",
"明教青石大道3",
"明教青石大道4",
"明教青石大道5",
"明教青石大道6",
"明教青石大道7",
"明教青石大道8",
"明教青石大道9",
"明教锐金旗大厅",
"明教山门",
"明教四门广场",
"明教天门男舍",
"明教天微堂",
"明教刑堂",
"明教悬天崖",
"南阳城",
"南阳迎宾楼",
"南阳悦来客栈",
"青城朝阳洞",
"青城古龙桥",
"青城古银杏树",
"青城呼应亭",
"青城盘建福宫",
"青城盘山磴道",
"青城青石大道",
"青城三岛石",
"青城三弯九倒",
"青城山路2",
"青城上清宫",
"青城松风观",
"青城天然图画",
"青城天师洞",
"青城听泉亭",
"青城小桥",
"青城驻鹤庄",
"青城祖师殿",
"泉州",
"泉州北门",
"泉州海港",
"泉州南门",
"泉州澎湖岛",
"泉州莆仙平原",
"泉州青龙会侧庭2",
"泉州青龙会侧庭3",
"泉州青龙会大庭",
"泉州青龙会前庭",
"泉州山路1",
"泉州山路2",
"泉州山路3",
"泉州山路4",
"泉州山路5",
"泉州西门吊桥",
"泉州中洲桥",
"泉州竹林小道",
"少林寺白衣殿",
"少林寺般若堂八部",
"少林寺般若堂二部",
"少林寺般若堂九部",
"少林寺般若堂六部",
"少林寺般若堂七部",
"少林寺般若堂三部",
"少林寺般若堂四部",
"少林寺般若堂五部",
"少林寺般若堂一部",
"少林寺藏经阁二楼",
"少林寺藏经阁一楼",
"少林寺茶室",
"少林寺厨房",
"少林寺达摩洞",
"少林寺地藏殿",
"少林寺东竹林小道",
"少林寺方丈楼",
"少林寺方丈室",
"少林寺防具库",
"少林寺鼓楼小院",
"少林寺广场",
"少林寺和尚院二部",
"少林寺和尚院六部",
"少林寺和尚院三部",
"少林寺和尚院四部",
"少林寺和尚院五部",
"少林寺和尚院一部",
"少林寺后殿",
"少林寺戒律院",
"少林寺精进场",
"少林寺练武场",
"少林寺罗汉堂八部",
"少林寺罗汉堂二部",
"少林寺罗汉堂九部",
"少林寺罗汉堂六部",
"少林寺罗汉堂七部",
"少林寺罗汉堂三部",
"少林寺罗汉堂四部",
"少林寺罗汉堂五部",
"少林寺罗汉堂一部",
"少林寺千佛殿",
"少林寺勤修场",
"少林寺山门殿",
"少林寺石阶",
"少林寺台阶",
"少林寺天王殿",
"少林寺武器库",
"少林寺西竹林小道",
"少林寺药品库",
"少林寺斋厅",
"少林寺钟楼一层",
"少林寺竹林",
"舍身崖地下石室1",
"舍身崖地下石室2",
"舍身崖房间1",
"舍身崖房间2",
"舍身崖房间3",
"舍身崖石洞",
"舍身崖石室1",
"舍身崖石室2",
"神龙教草坪",
"神龙教大道",
"神龙教大门",
"神龙教大厅",
"神龙教灌木林",
"神龙教海滩",
"神龙教空地",
"神龙教小屋",
"苏州白莲池",
"苏州宝和记",
"苏州北",
"苏州兵营",
"苏州茶馆",
"苏州春在楼",
"苏州打铁铺",
"苏州东门",
"苏州二仙亭",
"苏州枫桥",
"苏州府衙",
"苏州古木交诃",
"苏州憨憨泉",
"苏州寒山寺",
"苏州荷花厅",
"苏州虎丘山",
"苏州聚宝斋",
"苏州客店",
"苏州擂台前广场",
"苏州立春堂",
"苏州立雪堂",
"苏州留园",
"苏州马厩",
"苏州南",
"苏州南门",
"苏州千人石",
"苏州青石官道2",
"苏州狮子林",
"苏州试剑石",
"苏州书场",
"苏州书院",
"苏州孙武亭",
"苏州铁岭关",
"苏州听雨轩",
"苏州头门山",
"苏州万景山庄",
"苏州问梅阁",
"苏州戏园子",
"苏州玄妙观",
"苏州燕誉堂",
"苏州揖峰指柏轩",
"苏州真趣亭",
"苏州枕石",
"苏州致爽阁",
"苏州中",
"苏州紫金庵",
"台湾赤嵌城",
"台湾打狗港",
"台湾疯人院",
"台湾荒地",
"台湾鸡笼港",
"台湾力伐院",
"台湾力伐院私刑房",
"台湾日月潭",
"台湾桃花院",
"台湾形正院",
"台湾形正院金库",
"台湾正药居民区",
"台湾忠通府",
"泰山白鹤泉",
"泰山宝藏岭",
"泰山北天门",
"泰山碧霞祠",
"泰山大驿道",
"泰山东天门",
"泰山斗母宫",
"泰山二天门",
"泰山封禅台",
"泰山回马岭",
"泰山莲花峰",
"泰山龙门",
"泰山南天门",
"泰山日观峰",
"泰山山脚",
"泰山升仙坊",
"泰山石经峪",
"泰山试心石",
"泰山探海石",
"泰山天街",
"泰山围屏山",
"泰山五大夫松",
"泰山西天门",
"泰山一天门",
"泰山玉皇顶",
"泰山月观峰",
"泰山丈人峰",
"泰山岱宗坊",
"桃花岛",
"桃花岛兵器室",
"桃花岛厨房",
"桃花岛道具房",
"桃花岛墓道",
"桃花岛山洞",
"桃花岛山庄正厅",
"桃花岛思过室",
"桃花岛桃花轩",
"桃花岛卧房",
"桃花岛小屋",
"桃花山庄书房",
"桃花山庄小院",
"桃花山庄正门",
"天龙寺般若台",
"天龙寺崇圣宝殿",
"天龙寺慈悲院",
"天龙寺大门",
"天龙寺兜率大士院",
"天龙寺斗母宫",
"天龙寺晃天门",
"天龙寺牟尼堂",
"天龙寺清都瑶台",
"天龙寺清心阁",
"天龙寺瑞鹤门",
"天龙寺三无宫",
"天龙寺舍利塔1",
"天龙寺舍利塔2",
"天龙寺舍利塔3",
"天龙寺塔林",
"天龙寺无常阁",
"天龙寺无净阁",
"天龙寺无乐阁",
"天龙寺无我阁",
"天龙寺无无境",
"天龙寺翔鹤门",
"天龙寺雨花院",
"万劫谷草地",
"万劫谷大森林",
"万劫谷江边小路1",
"万劫谷江边小路2",
"万劫谷江边小路3",
"万劫谷澜沧江畔",
"万劫谷山路1",
"万劫谷山路2",
"万劫谷山路3",
"万劫谷山路4",
"万劫谷山坡",
"万劫谷善人渡",
"万劫谷石屋",
"万劫谷铁索桥",
"万劫谷卧室",
"万劫谷小厅",
"万劫谷药房",
"武当柏林",
"武当朝天宫",
"武当二天门",
"武当复真观",
"武当广场",
"武当果园小路1",
"武当果园小路2",
"武当好汉坡",
"武当虎头岩",
"武当黄土路2",
"武当黄土路3",
"武当会仙桥",
"武当解剑岩",
"武当金殿",
"武当金顶",
"武当榔梅园",
"武当磨针井",
"武当南岩峰",
"武当南岩宫",
"武当南岩宫高台",
"武当青石大道1",
"武当三不管",
"武当三老峰",
"武当三清殿",
"武当三天门",
"武当山路1",
"武当舍身崖",
"武当十八盘",
"武当十二莲台",
"武当石阶",
"武当石梁",
"武当石柱",
"武当松林",
"武当太子坡",
"武当太子岩",
"武当桃园",
"武当桃园篱笆1",
"武当桃园篱笆2",
"武当桃园小路10",
"武当桃园小路8",
"武当桃园小路9",
"武当头天门",
"武当乌鸦岭",
"武当五老峰",
"武当小吃店",
"武当玄岳门",
"武当遇真宫",
"武当紫金城",
"武当紫霄宫大门",
"武功",
"武功富家大门",
"武功富家大堂",
"武功富家小院",
"武功酒楼",
"武功酒楼二楼",
"武功客店",
"武功客店二楼",
"武功民居1",
"武功民居2",
"武功土地庙",
"西域草原",
"西域大漠",
"西域嘉峪关",
"西域南疆沙漠",
"西域丝绸之路1",
"西域丝绸之路2",
"西域丝绸之路3",
"西域丝绸之路4",
"西域天山脚下",
"西域天山山路1",
"西域天山山路2",
"侠客岛大厅",
"侠客岛洞门",
"侠客岛海滩",
"侠客岛夹鳖石",
"侠客岛摩天崖",
"侠客岛木屋",
"侠客岛瀑布",
"侠客岛山路",
"侠客岛山路1",
"侠客岛山路6",
"侠客岛山门",
"侠客岛石洞1",
"侠客岛石洞2",
"侠客岛石洞6",
"侠客岛石洞7",
"侠客岛石洞8",
"侠客岛书房",
"侠客岛树林",
"侠客岛望云台",
"侠客岛武器库",
"侠客岛小吃店",
"侠客岛休息室",
"侠客岛崖底",
"侠客岛一线天",
"侠客岛迎宾馆",
"侠客岛甬道",
"襄阳安抚使衙门",
"襄阳北兵营",
"襄阳草地",
"襄阳草地1",
"襄阳茶馆",
"襄阳大校场",
"襄阳当铺",
"襄阳东北",
"襄阳东兵营",
"襄阳东南",
"襄阳赌场",
"襄阳福威镖局",
"襄阳郭府大门",
"襄阳将军府大门",
"襄阳聚义馆",
"襄阳客栈",
"襄阳马厩",
"襄阳觅香楼",
"襄阳民居1",
"襄阳民居2",
"襄阳木匠铺",
"襄阳南兵营",
"襄阳钱庄",
"襄阳书店",
"襄阳铁匠铺",
"襄阳西北",
"襄阳西兵营",
"襄阳西南",
"襄阳新罗坊",
"襄阳学堂",
"襄阳药铺",
"襄阳忠烈祠",
"星宿海",
"星宿海日月洞",
"星宿海山间平地",
"星宿海石道",
"星宿海天山山路1",
"星宿海天山山路2",
"星宿海天山山路3",
"星宿海天山山路4",
"星宿海小路",
"星宿海逍遥洞",
"星宿派储藏室",
"雪山寺",
"雪山寺藏经阁",
"雪山寺藏经室",
"雪山寺厨房",
"雪山寺大殿",
"雪山寺地牢",
"雪山寺库房",
"雪山寺密室",
"雪山寺禅室",
"血刀门大雪山",
"血刀门大雪山口4",
"血刀门大雪山口6",
"血刀门大雪山口7",
"血刀门大雪山山谷8",
"血刀门大雪山山谷9",
"血刀门棍巢",
"血刀门客店",
"血刀门山洞1",
"血刀门山洞2",
"血刀门山脚",
"血刀门山路1",
"血刀门山路2",
"血刀门山路4",
"血刀门山路5",
"血刀门山路6",
"血刀门山路7",
"血刀门圣湖",
"血刀门土路1",
"血刀门土路2",
"血刀门土路3",
"血刀门忘忧谷",
"血刀门小路1",
"血刀门小路2",
"血刀门小路3",
"血刀门小路4",
"血刀门雪山北麓",
"血刀门雪山路1",
"血刀门雪山路2",
"血刀门雪山路3",
"燕子坞泊舟坞",
"燕子坞参合居",
"燕子坞长廊",
"燕子坞厨房",
"燕子坞穿堂",
"燕子坞翠霞堂",
"燕子坞汇珍园",
"燕子坞梨香苑",
"燕子坞龙凤厅",
"燕子坞品笛庭",
"燕子坞沁芳阁",
"燕子坞青冢",
"燕子坞秋爽斋",
"燕子坞试剑台",
"燕子坞水云轩",
"燕子坞太湖",
"燕子坞听香水榭",
"燕子坞听雨居",
"燕子坞晓寒厅",
"燕子坞小径",
"燕子坞仪门",
"燕子坞竹林",
"燕子坞缀锦楼",
"燕子坞啖糯厅",
"扬州北门",
"扬州北驿道",
"扬州兵营",
"扬州财主大门",
"扬州草地1",
"扬州草地7",
"扬州草地8",
"扬州春来茶馆",
"扬州当铺",
"扬州东北",
"扬州东门",
"扬州东南",
"扬州东驿道",
"扬州赌场",
"扬州客店",
"扬州丽春院",
"扬州丽春院二楼",
"扬州马厩",
"扬州密林10",
"扬州密林11",
"扬州密林12",
"扬州密林4",
"扬州密林5",
"扬州密林9",
"扬州南门",
"扬州南浔",
"扬州钱庄",
"扬州青竹林2",
"扬州山路1",
"扬州山路2",
"扬州书院",
"扬州树林",
"扬州树林2",
"扬州树林3",
"扬州树林6",
"扬州桃花村",
"扬州桃花谷",
"扬州桃花林",
"扬州桃花坪",
"扬州桃花溪",
"扬州田地",
"扬州武道场",
"扬州武馆",
"扬州武庙",
"扬州西北",
"扬州西门",
"扬州西门大道",
"扬州西南",
"扬州衙门大门",
"扬州药铺",
"扬州宜兴",
"扬州醉仙楼",
"终南山白马潭",
"终南山柏树林",
"终南山半山亭",
"终南山抱子岩",
"终南山草堂寺",
"终南山翠屏峰顶",
"终南山翠屏谷",
"终南山大官道",
"终南山大校场",
"终南山道路11",
"终南山道路13",
"终南山访真桥",
"终南山佛爷掌",
"终南山观日台",
"终南山黑凤洞",
"终南山脚",
"终南山教碑",
"终南山金莲阁",
"终南山老妪岩",
"终南山普光寺",
"终南山日月岩",
"终南山山道1",
"终南山山道2",
"终南山山道3",
"终南山山道8",
"终南山山道9",
"终南山山间小径14",
"终南山山间小径15",
"终南山山间小径16",
"终南山山路1",
"终南山山路10",
"终南山山路12",
"终南山山路2",
"终南山山路3",
"终南山山路4",
"终南山山路5",
"终南山山路6",
"终南山山路7",
"终南山神禾原",
"终南山石阶1",
"终南山石阶2",
"终南山石阶3",
"终南山石阶4",
"终南山石阶5",
"终南山石阶6",
"终南山石阶7",
"终南山石阶8",
"终南山试剑岩",
"终南山树林10",
"终南山树林7",
"终南山树林8",
"终南山树林9",
"终南山太乙池",
"终南山小河边",
"终南山遇真宫",
"重阳宫",
"重阳宫大门",
"重阳宫弟子居",
"重阳宫后山",
"重阳宫静修室",
"重阳宫练功房",
"重阳宫膳堂",
"重阳宫显真堂",
"重阳宫小花园1",
"重阳宫小花园2",
"重阳宫小花园3",
"重阳宫小路",
"重阳宫休息室",
"重阳宫遇真宫",
"重阳宫禅房",
"嵩山朝天门",
"嵩山崇圣门",
"嵩山法王寺",
"嵩山封禅台",
"嵩山峻极禅院山门",
"嵩山芦岩瀑布",
"嵩山启母石",
"嵩山启母阙",
"嵩山山道1",
"嵩山山道2",
"嵩山山道3",
"嵩山山道4",
"嵩山山道5",
"嵩山山道6",
"嵩山塔院",
"嵩山太室阙",
"嵩山天中阁",
"嵩山铁梁峡",
"嵩山月台",
"嵩山中岳大殿",
"嵩山嵩阳书院",
"嵩山嵩岳寺",
"嵩山嵩岳塔",
"逍遥林打铁屋",
"逍遥林工匠屋",
"逍遥林酒家",
"逍遥林木屋",
"逍遥林石屋",
"逍遥林树林",
"逍遥林小道1",
"逍遥林小道2",
"逍遥林小道3",
"逍遥林小木屋",
"逍遥林小屋"
};
/*
char global_weapon_name[MAX_WEAPON_NUM][40] = {
	"baihongjian","bilinzhen","bishou","blade_1","blade_2","cleansword","dadao","zimuzhen",
		"dadao2","dafu","dagger","duanjian","fandog_sword","fenshuici","fork","fuchen","futou","green_sword",
		"green_water_sword","hammer","heilongbian",	"hothammer","huaji","hugesword","huoqiang","jinhua","jinlun",
		"jiujiebian","kandao","kuihuazhen","langyabang","leizhendang","longquansword","mandao","panguanbi",
		"putongbishou","qimeigun","qin","qingzugang","qingzuzang","qinqin_sword","ring_whip","ruanjian","sea_wood",
		"senggun","shebian","shenghuo_ling","shezhang","shield","shunvjian","shutonggun","snowsword","sword_1",
		"sword_2","sword_3","taomujian","tiepipa","tongren","walkingstick","wandao","wodao","wuqing_sword","xblade",
		"xem_sword","xiao","xiuhua","xuantiesword","xuedao","yangbian","yaochu","yaoqin","yinlun","youlongsword",
		"yufeng_zhen","yuxiao","yuzhu_zhang","zijinchui","zijin_staff",
};

char global_cloth_name[MAX_CLOTH_NUM][40]={
	"cloth","pixue","dao_xie","daopaocyan_cloth","daogu_cloth","female1_cloth","female2_cloth","female3_cloth",
		"female4_cloth","female5_cloth","female6_cloth","female7_cloth","female8_cloth","female_shoe","flower_shoe",
		"green_cloth","greenrobe","greyrobe","gunny_shoes","heiyi","hongchou","hongchouxiaoshan","huangshan","hui_cloth",
		"huwan","huyao","jiasha","jin","jindai","jinduan","jingang_zhao","junfu","majia","male1_cloth","male2_cloth",
		"male3_cloth","male4_cloth","male5_cloth","male6_cloth","male7_cloth","male8_cloth","male_shoe","necklace",
		"ni_cloth","ni_xie","p_jiasha","pink_cloth","piqiu","qing_cloth","qingpao","qingyi","r_jiasha","ring","rose",
		"rover","seng_cloth","seng_xie","sengmao","sengxie","shepi","shoe","shoutao","shuikao","shouzhuo","tiejia",
		"surcoat","test","toukui","weibo","white_robe","wuxingfu","xu_cloth","xuan_cloth","y_jiasha","yaodai",
		"yayi_cloth","ycloth","yupei","zhaohong","zhanyi","zhenzhu","tiezhitao","zichoushan","b_jiasha","baguafu",
		"baichou","baipao","baiyi","baojia","bduanqun","beixin","belt","blackcloth","bluecloth","boots","bu_shoes",
		"bupao","c_jiasha","caoxie","changpao","changpao2","cheng_cloth","choupao","cloth2","color_dress","connie",
		"cuiyu","cycle","cynrobe","dachang","dao_cloth","diaopi","doupeng","doupeng2","dress","feather","fu_cloth",
		"goldring","goupi","guazi","gui_dress","hat","hupi","hushenfu","jade_belt","jinsijia","jjunfu","kenao","lace",
		"linen","liu_dress","luo_cloth","magcloth","magua","maotan","marry_dress","mini_dress","moon_dress","pink_dress",
		"qi_dress","qingyi2","qun","red_cloth","red_dress","ruanwei","scarf","sha_dress","shoes","shoupa","skirt",
		"shudai","tduanqun","tiebeixin","tiehuwan","tiehuyao","tieshou","tongqun","ttoujin","wchangqun","wcloth","wdahui",
		"whitecloth","whitecloth1","xian_cloth","xiaoao","xiu_cloth","xiu_scarf","yan_dress","zi_dress","bandage","mask",
};

char global_food_name[MAX_FOOD_NUM][40]={
	"baihe","baixiang","baozi","duanchang","feicui","gourou","gouroutang","guijia","guiyuan","heiyugao","honghua",
		"hdjiudai","hulu","jiaohuaji","jiaxin_biji","jinchuang","jinchuang_yao","jitui","jiudai","jindan","kaoya",
		"liuli_qiezi","mala_doufu","marz","menghan_yao","mian","mitao","mizhitianou","moyao","niupidai","nuerxiang",
		"nverhong","peanut","putizi","qingdan","qingke_m","qingshui_hulu","renshen","renshenguo","rice","shanhu_baicai",
		"shanshen","shedan","shedangao","sherou","shouwu","soup","suanmei","suji","suya","tanghulu","tianqi",
		"tianxiang_gao","turou","tofu","wuchangdan","wuming","x_drug","xiangcha","xiaohuan_dan","xiongdan","xionghuang",
		"xuejie","xueli","xuelian","yadan","yancao","yangxin","yaofen","yuchandan","yuchi","zaisheng","zongzi","zhutou",
		"zhujingchan","yezi","yeerba","yangrou","yangjing","xxqingxin_san","xuelian2","xiaren2","xiang","backleg",
		"soup2","shrimp","sanxiaosan","rice3","qingcha","qiguoji","puercha","pork","ping","paomo","nang","mixian",
		"mangguo","labazhou","kongquedan","kaoyangtui","jiuping2","jiuping","jiuhua","jiu","huotui2","huotui","hulu2",
		"hulu1","hu","hedinghong","hamigua","guiling","geng","gaoyao","gao4","gao3","gao","furong_huagu","fuling",
		"fotiaoqiang","food","fish","fengmi","fen","egg","doujiang","dawancha","dan","dahuan_dan","chicken","cha2","cha",
		"caomei","cake","bowl","bottle","bocai_fentiao","birddie","bing_6","bing_5","bing_4","bing_3","bing_2","bing_1",
		"bicanfeng","basi_shanyao","baozi2","baiyunwan","baihua","jiu_mijiu","luobo","caogeng","jingxin_san","honey",
};
*/