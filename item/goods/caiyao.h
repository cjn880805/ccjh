//cai.h 菜肴
//秦波 2002、12、30

FOOD_BEGIN(CIcaiyao);

virtual void create(int nFlag = 0)
{
	static char cai[45][20]={"熏腊肠","醉子鸡","东坡肉","五花焖肉","红烧素鹅","宫保鸡丁","麻辣肚丝","红油肺片","嫩汆猪肝","走油脆肠","青丝熏鱼","糖醋排骨","京酱肉丝","油炝大虾","细扒头肉","麝香冬笋","爆炒腰花","翡翠豆腐","三鲜腐竹","时鲜蔬菜","脆皮烤鸭","清蒸鲈鱼","麻婆豆腐","芙蓉蛤蜊","荷包里脊","芙蓉蟹斗","宫保野兔","爆炒田鸡","绣球乾贝","麻辣口条","油焖草菇","百花鸭舌","蕃茄马蹄","腰果芹心","蜜汁蕃茄","山珍蕨菜","五香仔鸽","糖醋荷藕","清炸鹌鹑","白扒鱼唇","天香鲍鱼","三仙丸子","枸杞鱼米","酸辣黄瓜","拔丝香蕉"};
	
	int index=random(45);
	set_name(cai[index]);
	
	set_weight(20000);
	set("unit", "盘");
	char msg[255];
	
	set("long",snprintf(msg, 255,"这是一盘让人垂涎欲滴的「%s」",cai[index]));
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	long i;
	long e;
	
	i=current_time;
	e=me->query_temp("cao/overtime");
	if (i<e)
	{
		if(EQUALSTR(who->id(1) , querystr("cao/id")) && EQUALSTR(who->name(1), querystr("cao/name")) 
			&& EQUALSTR((who->environment())->name(1) , querystr("cao/map")) &&EQUALSTR(me->id(1) , querystr("owner1"))  )
		{
			static char hows[29][255] = {
				"万般幸福地",
					"鬼鬼祟祟地",
					"红光满面地",
					"乐滋滋地",
					"极为严肃地",
					"点头哈腰地",
					"感激涕淋地",
					"板着脸",
					"激动得浑身颤抖，",
					"庄严地看着大家，然后勇敢地",
					"呲牙咧嘴地",
					"秀里秀气地",
					"满脸狐疑地",
					"翻翻白眼，",
					"摇头晃脑地",
					"抿嘴一笑，",
					"饿狼一样",
					"笨手笨脚地",
					"肥头肥脑地",
					"满脸堆笑故作正经地",
					"推开众人，摆好架式，",
					"油头粉面地",
					"兴奋得满头大汗，",
					"面黄肌瘦地",
					"抹去眼角的泪花，",
					"撮撮手，一跺脚，",
					"张牙舞爪地",
					"十分谦虚地",
					"羞得满脸通红，",
			};
			
			static char manners [27][255]  = {
				"把$HIC「$n」$COM在手心里反复撮了几下，",
					"把$HIC「$n」$COM在地上疯狂地跺扁，",
					"把$HIC「$n」$COM在墙上嘭地一声砸开，",
					"把$HIC「$n」$COM在心口仔细暖了一下，",
					"把$HIC「$n」$COM往油锅里迅速一炸，然后",
					"亲了亲$HIC「$n」$COM，",
					"使劲撕开$HIC「$n」$COM，一点一点地",
					"在$HIC「$n」$COM的外面抹上一层红红的蕃茄酱，",
					"拿起$HIC「$n」$COM蘸着厚厚的红糖，",
					"在$HIC「$n」$COM上撒了一大把盐，",
					"把$HIC「$n」$COM拿起就着两片酸黄瓜，",
					"把$HIC「$n」$COM在酱油里一蘸，品着味",
					"把$HIC「$n」$COM在辣酱里点了一点，咝咝地",
					"把$HIC「$n」$COM在开水里一泡，趁热",
					"把$HIC「$n」$COM在火上一燎，赶紧",
					"用一副刀叉切开$HIC「$n」$COM，",
					"用竹筷夹起$HIC「$n」$COM",
					"含一口绍兴酒喷在$HIC「$n」$COM上，",
					"把$HIC「$n」$COM用自来水洗得干干净净，",
					"在$HIC「$n」$COM上舔了半天，",
					"在$HIC「$n」$COM上撒一层榨菜丝，",
					"在$HIC「$n」$COM上裹一层火腿奶酪，",
					"把$HIC「$n」$COM和葱姜蒜末拌在一起，",
					"把$HIC「$n」$COM捣碎，拌上生菜，",
					"把$HIC「$n」$COM切成小块，加上鸡丁花生热热地在油锅里炒成宫保$HIC「$n」$COM，",
					"把$HIC「$n」$COM放进锅里，加上酱油红糖小火炖成红烧$HIC「$n」$COM，",
					"把$HIC「$n」$COM放在在锅里倒醋撒糖芡成一盘糖醋$HIC「$n」$COM，",
			};
			
			static char actions [24][255] = {
				"张开樱桃小口吞了下去",
					"用两片大嘴唇咬住只一吸就咽了下去",
					"一歪嘴巴吞了下去",
					"再往嘴里乒乒乓乓一扔",
					"皱着眉头痛心疾首地吃了下去",
					"望天上一扔，伸出脖子叭地一声接住",
					"往嘴巴用力使劲里一塞",
					"硬着头皮贼喊捉贼地吃了下去",
					"吧嗒吧嗒贼眉鼠眼地吃了下去",
					"含在嘴里如火如荼热气腾腾地吞了下去",
					"有滋有味连手指都吃了下去",
					"嚼都没嚼就伸脖踮脚地咽了下去",
					"肥肥地往下一吞",
					"唏唏溜溜就岔着气吃下了肚子",
					"一点点咬着吃了岔了气",
					"张开血盆大口，倒拎着往嘴里一扔",
					"吃得神经错乱眼冒金星",
					"吃得如痴如狂东倒西歪",
					"吃得神采奕奕情窦大开",
					"吃得神魂颠倒四面楚歌",
					"吃得翻肠倒肚天昏地暗",
					"狼吞虎咽地反反复复左嚼右嚼咽了下去",
					"咔嚓咔嚓地大嚼了起来，只一会儿就整个连假牙都咽了下去",
					"痛苦不堪地吃了下去",
			};
			
			char msg[255];
			message_vision (snprintf(msg, 255,"\n$HIC$N已经饿得望眼欲穿，%s%s%s。",hows[random(29)],manners[random(27)],actions[random(24)]), who,this);

			me->delete_temp("cao/id");
			me->delete_temp("cao/name");
			me->delete_temp("cao/map");
			me->delete_temp("cao/overtime");
			me->add_temp("cao/count",1);

			reward_exp(me);
			
			destruct(this);
			return 1;
		}
	}
	return notify_fail("不能对对方使用这个物品。");
}

//给经验
void reward_exp(CChar * me)
{
	char msg[255], tmp[80];

	int exp = 20+me->query("cao/count")+random(30);
	me->add("combat_exp", exp);
	int money=20+random(me->query("cao/count")+30);
	CMoney::Pay_Player(me, money);

	if(me->query_temp("cao/count")>200)
		me->delete_temp("cao/count");

	if(me->query_temp("weight"))
	{
		me->set_weight(me->query_temp("weight"));
		me->delete_temp("weight");
	}
	me->delete_temp("no_fei");
	
	tell_object(me, snprintf(msg, 255, "$HIR你完成了替曹掌柜的送菜任务，获得了%s点经验、%d文江湖货币！\n", chinese_number(exp, tmp),money));

	me->FlushMyInfo();
}
FOOD_END;
