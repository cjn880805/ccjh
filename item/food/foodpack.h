FOOD_BEGIN(CIfoodpack);

virtual void create(int nFlag = 0)
{
	set_name( "���������");

	set("wield_position", WIELD_HEAD);	
 	set_weight(20000);

	set("unit", "��");
	set("long", "����һ�����ƵĽ�����������ڴ�֮ǰ�㿴����������ʲô��");
	set("value",30000);
};


virtual int do_use(CChar * me, CContainer * target)
{
	say("һ����װ�����Ľ����������", me);
	AddMenuItem("���ڲ𿪡�", "$0open $1", me);
	AddMenuItem("������˵", "", me); 
	SendMenu(me);

    return 1; 
}

virtual int Can_Use()
{
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{

	if(strcmp(comm, "open") == 0)
		return do_open(me,arg);

	return CItem::handle_action(comm, me, arg);
}



int do_open(CChar * me, char * arg)
{
/*	static struct{
		char name[20], id[20];
		int hp, mp;				//�ָ���hp, mpֵ
		LONG weight;			//����
		LONG val;				//��ֵ	
		int drink;				//�Ƿ�ȵ�
	}yao[21] = {
		{"��Ҷһ֦��",	"xiaolong bao", 20, 0, 100, 40, 0,},
		{"�ϻ�����",   "chaye dan", 0, 20, 200, 60, 0,},
		{"ʯ����",   "tang hulu", 40, 10, 200, 75, 0,},
		{"����ӡ",   "zhima su", 50, 0, 500, 100, 0,},
		{"����������",	 "beijing guopu", 50, 20, 2000, 150, 0,},
		{"͸",	"xingren lu", 0, 50, 2000, 250, 1,},
		{"����",		"kao e", 75, 0, 5000, 300, 0,},
		{"����",		"cha tang", 0, 75, 1000, 400, 1,},
		{"����ͷ",	"er guo tou", 50, 50, 1000, 430, 1,},
		{"ţ���",	"niu rou geng", 100, 0, 1500, 450, 0,},
		{"��Ԫ��",  "guiyuan dan",		100, 0,		1200, 360, 0,},
		{"�����",   "huishen gao",		150, 0,		1500, 360, 0,},
		{"������",	 "buqi wan",		250, 0,		2000, 360, 0,},
		{"�ٻ��۾���", "baihua gao",		0, 100,		2000, 360, 0,},
		{"��Ѫ��",		"huixue gao",	400, 0,		2000, 480, 0,},
		{"�ӹ�ɢ",	"jiegu san",		500, 0,	1000, 480, 0,},
		{"������¶",	"tianxian yulu",	250, 250,	3000, 600, 1,},
		{"��ת����",   "jiuzhuan dan",	500, 100,	3500, 1200, 0,},
		{"����������", "tianxiang gao",	1000, 0,	1000, 1800, 0,},
		{"�󻹵�", "dahuan dan",			0, 250,		2500, 1800, 0,},
		{"��͢�ط�",	"gongting mifang",	1500, 0,	1000, 1800, 0,},
	};

	int lvl = random(21);

	set("index", lvl + 1);

	CContainer * 

	set_name(yao[lvl].name, yao[lvl].id);

	set("hp_supply", yao[lvl].hp);
	set("mp_supply", yao[lvl].mp);

	set("base_value", yao[lvl].val);
	set("base_weight", yao[lvl].weight);
		
	if(yao[lvl].drink)
	{
		set("eat_msg", "$N��$nһ��������");
	}
	else
		set("eat_msg", "$N��$n�Ե��ˡ�");

	set("food_remaining", 1);

	set_amount(1);

	return 1;
*/
	message_vision("$N����������˺����һ�������������",me);
	CContainer * drug;
	drug=load_item("yaopin_1");
	drug->move(me);
	drug=load_item("yaopin_1");
	drug->move(me);
	drug=load_item("yaopin_1");
	drug->move(me);
	drug=load_item("yaopin_1");
	drug->move(me);
	drug=load_item("yaopin_2");
	drug->move(me);
	drug=load_item("yaopin_2");
	drug->move(me);
	drug=load_item("yaopin_4");
	drug->move(me);
	message_vision("$N������Ķ���ȡ���������濴��һ�顣",me);
	if (random(4))
		me->command("sigh");
	else
		me->command("ah");
	destruct(this);
	return 1;
	
}

FOOD_END;
