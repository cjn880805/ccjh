//sword_3.h
//宝剑
//Lanwood 2001-02-03

EQUIP_BEGIN(CIsword_3);

virtual void create(int nFlag = 0)	
{
	static struct{
		char name[20];
		char id[20];
		int  damage;			//伤害力
		char apply[20];	   		//附加属性
		int	 apply_value;		//附加值
		LONG val;				//价值
		LONG weight;			//重量
		int  lvl;				//装备等级限制
	} jian[8] = {
		{"龙胆剑", "longdan jian", 150, "str", 5, 1000, 10000, 20,},
		{"烈焰剑", "lieyan jian", 150, "str", 5, 1500, 12000, 25,},
		{"青风刃", "qingfen ren",  160, "dex", 5, 1800, 10000, 25,},
		{"破玉剑", "poyu jian", 170, "int", 6, 2000, 18000, 25,},
		{"干将剑", "ganjian jian", 180, "str", 8, 2200, 20000, 30,},
		{"莫邪剑", "moye jian", 200, "dex", 8, 2500, 20000, 30,},
		{"轩辕剑", "xuyuan jian", 220, "str", 10, 2800, 25000, 40,},
		{"盘古剑", "pangu jian", 250, "str", 10, 3000, 20000, 50,},
	};

	int lvl = random(8);

	if(nFlag) lvl = nFlag - 1;

	set_name( jian[lvl].name, jian[lvl].id);
	set("index", lvl + 1);
	
	set("wield_position", WIELD_RIGHT_HAND);
	set("skill_type", "sword");
	set_weight(jian[lvl].weight);
		
	set("unit", "柄");
	set("value", jian[lvl].val);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回剑鞘。");
	set("apply/damage", jian[lvl].damage);	
	set("equip_lvl", jian[lvl].lvl);
	
	set("duration", 150);
/*
	if(jian[lvl].apply_value)
	{
		char str[40];
		set(snprintf(str, 40, "apply/%s", jian[lvl].apply), jian[lvl].apply_value);
	}

	if(lvl == 6) set("apply/dex", 5);
	if(lvl == 7) set("apply/dex", 5);
*/
};

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIW$w在$n身上化成一道白光，消散不见了……$COM";
	}
	
	return 0;
}

EQUIP_END;