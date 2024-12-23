//musicbook1.h
//旧曲谱 music
//lanwood 2001-04-05

ITEM_BEGIN(CImusicbook1);

void create(int nFlag = 0)	
{
	char msg[40], tmp[10];

	int lvl = random(10);

	if(nFlag) lvl = nFlag - 1;

	set("index", lvl + 1);

	set_name( snprintf(msg, 40, "旧曲谱(第%s册)", chinese_number(lvl + 1, tmp)));

 	set_weight(50);		//set item weight

	set("unit", "本");
	set("long", "这是一本薄薄的小册，上面谱了曲子。");
	set("value", 500);
	set("material", "silk");
	set("skill/name","music");
	set("skill/exp_required", lvl * 10000);
	set("skill/jing_cost",20);
	set("skill/difficulty",20);	
	set("skill/max_skill", lvl * 20 + 20);	
	set("skill/min_skill", lvl * 20);  
};

ITEM_END;
