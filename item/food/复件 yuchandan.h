//Sample for ITEM ѩ����󸵤
//Modified By Lanwood
//�ɽ���ֶ���
//data: 2001-02-14
YAOPIN_BEGIN(CIyuchandan);

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ѩ����󸵤");	//set item name

	set("unit", "��");
	set("long", "���Ǹ�����������ҩ������ⶾ���ˣ�����Ƿ���");
	set("base_value", 500);
		
	set_amount(1);
};
virtual int do_use(CChar * me, CContainer * target)
{
	message_vision( "$N����һ��ѩ����󸵤��ֻ��һ�ɺƵ�����ֱӿ��������æ��ϥ��������Ŀ�˹�..." , me);

	//�⼸�ֶ�
	struct{
		char poison[40], name[40];		//��������
		int  effect;			//��Ч
		int  diff;				//�Ѷ�
	} jiedu [13] =
	{
		{"feng_poison",		"�䶾",			25,		0,},
		{"flower_poison",	"�ϳ�����",		25,		6,},
		{"ice_poison",		"��������",		10,		20,},
		{"jy_poison",		"�����׹�צ��",	5,		20,},
		{"rainbow_poison",	"���׷����",   5,		20,},
		{"rose_poison",		"��õ�嶾",		25,		5,},
		{"sanxiao_poison",	"��Ц��ңɢ",	5,		14,},
		{"scorpion_poison",	"Ы��",			40,		0,},
		{"snake_poison",	"�߶�",			50,		0,},
		{"xx_poison",		"�����ƶ�",		2,		8,},
		{"yufeng_poison",	"�����",		8,		8,},
		{"zhua_poison",		"��Ѫ��ץ",		4,		16,},
		{"zm_poison",		"��ĸ����֮��",	4,		16,},
	};
	
	int level = me->query("level");
	LONG poison;
	char msg[255];

	for(int du = 0; du < 13; du ++)
	{
		if( (poison = me->query_condition(jiedu[du].poison)) <= 0) continue;
		if(random(level + jiedu[du].diff) >= jiedu[du].diff)
		{
			//���Խ�
			me->apply_condition(jiedu[du].poison, poison - jiedu[du].effect);
			tell_object(me, snprintf(msg, 255, "���е�%s�����ˡ�", jiedu[du].name));
			break;
		}
	}

	me->start_busy(2);
	destruct(this);
	return 1;
}

YAOPIN_END;
