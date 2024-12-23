//结婚装备
//marry_1.h
//Lanwood 2001-03-17

EQUIP_BEGIN(CImarry_1);

virtual void create(int nFlag = 0)	
{
	static struct{
		char name[15], id[20];
		int wield_position;
		LONG  weight, value;
		int armor;
		char attr[10];
		int modify;

		char wear_msg[80], unwear_msg[80];
	}armor[15]={
		{"黑色新郎礼服", "marry dress", WIELD_ARMOR, 500, 8000, 3, "per", 3, "$YEL$N穿上一件$n，顿时容光焕发。", "$N脱下一件$n。"},
		{"大红新娘礼服", "marry dress", WIELD_ARMOR, 500, 8500, 2, "per", 3, "$HIY$N穿上一件$n，顿时光彩照人。", "$N脱下一件$n。"},
		{"新郎帽", "cap", WIELD_HEAD, 800, 500, 1, "per", 1, "$N戴上一顶$n。", "$N摘下$n。"},
		{"天然紫水晶项链", "lace",  WIELD_NECK, 800, 1500, 1, "per", 1, "$N戴上一串$n，立刻明艳动人。", "$N取下一串$n细心收好。"},
		{"彩纹贝壳项链", "lace", WIELD_NECK, 500, 2500, 1, "per", 1, "$N戴上一串$n，立刻明艳动人。", "$N取下一串$n细心收好。"},
		{"紫金钻石项链", "lace", WIELD_NECK, 500, 3500, 1, "per", 2, "$N戴上一串$n，立刻明艳动人。", "$N取下一串$n细心收好。"},
		{"珍珠项链", "lace", WIELD_NECK, 300, 1500, 1, "per", 1, "$N戴上一串$n，立刻明艳动人。", "$N取下一串$n细心收好。"},
		{"订婚戒指", "ring", WIELD_RING, 100, 2500, 1, "per", 1, "$N拿起一枚$n，小心的套在左手无名指上。", "$N摘下一枚$n，细心收好。"},
		{"缅甸玉镯", "wrist", WIELD_WRIST, 500, 1500, 1, "per", 1, "$N拿起一只$n，小心的套在手腕上。", "$N取下一只$n，细心收好。"},
		{"翡翠夜光珠", "ye ming zhu", WIELD_LEFT_ERR, 800, 5500, 1, "per", 2, "$N楚楚动人的将$n戴在左耳上。", "$N小心的取下$n，细心收好。"},

		{"贝壳耳环", "er huan", WIELD_ERR, 200, 1500, 1, "per", 1, "$N取出$n戴在耳上。", "$N摘下耳上的$n，细心收好。"},
		{"大红镶丝披风", "pi feng", WIELD_MANTLE, 300, 2500, 2, "per", 2, "$N披上一件$n。", "$N脱下一件$n。"},
		{"黑色长筒皮靴", "pi xue", WIELD_BOOT, 500, 800, 2, "per", 1, "$N穿上一双$n。", "$N脱下一双$n。"},
		{"红色绣花鞋", "shoes", WIELD_BOOT, 300, 500, 1, "per", 1, "$N穿上一双$n。", "$N脱下一双$n。"},
		{"大红腰带", "waist", WIELD_WAIST, 500, 1500, 2, "per", 1, "$N将一条$n系在腰间。", "$N解开$n。"},
	};

	int idx = random(15);
	if(nFlag) idx = nFlag - 1;

	set("index", idx + 1);
	set_name(armor[idx].name, armor[idx].id);	

	set("wield_position", armor[idx].wield_position);	
 	set_weight(armor[idx].weight);	
         
	set("unit", "件");
	set("value", armor[idx].value);
		
	set("apply/armor", armor[idx].armor);
	if(armor[idx].modify)
	{
		char key[40];
		
		snprintf(key, 40, "apply/%s", armor[idx].attr);
		set(key, armor[idx].modify);		
	}
	
	set("wear_msg", armor[idx].wear_msg);
	set("remove_msg", armor[idx].unwear_msg);
};

EQUIP_END;
