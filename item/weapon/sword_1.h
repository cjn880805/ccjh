//sword_1.h
//宝剑

EQUIP_BEGIN(CIsword_1);

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
	} jian[8] = {
		{"桃木剑", "taomu jian", 15, "dex", 1,	150, 2000,},
		{"长剑", "chang jian", 18, "", 0,		200, 5000,},
		{"钢剑", "gang jian", 15, "", 0,			200, 5000,},
		{"双刃剑", "shuang jian", 15, "str", 2,	280, 8000,},
		{"黑木剑", "black sword", 18, "int", 1,	360, 10000,},
		{"短剑", "duan jian", 20, "", 0,			120, 3000,},
		{"铁剑", "tie jian", 30, "dex", -1,		200, 15000,},
		{"钝剑", "dun jian", 25, "con", 2,		250, 8000,},
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
	
	if(jian[lvl].apply_value)
	{
		char str[40];
		set(snprintf(str, 40, "apply/%s", jian[lvl].apply), jian[lvl].apply_value);
	}
};

EQUIP_END;