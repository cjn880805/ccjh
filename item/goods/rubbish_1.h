//rubbish_1.h
//����
//Teapot 2001-02-03

ITEM_BEGIN(CIrubbish_1);

virtual void create(int nFlag = 0)	
{
	static struct{
		char name[20];
		char id[20];
		LONG weight;			//����
		int  exp;				//��������
	} jian[8] = {
		{"�㽶Ƥ", "xiangjiao pi",12000,10,},
		{"����Ƥ", "xigua pi",13000,15,},
		{"ƻ����", "pingguo he",  8000,20,},
		{"��ľͷ", "po mutou", 10000,25,},
		{"������", "lan li", 20000,30,},
		{"��Ƭ", "bu pian", 5000,35,},
		{"����Ƭ", "sui tao", 12200,40,},
		{"��������", "yila guan", 14200,40,},
	};

// no_get 1
// no_give 1

	int lvl = random(8);

	if(nFlag) lvl = nFlag - 1;

	set_name( jian[lvl].name, jian[lvl].id);
	set_weight(jian[lvl].weight);
	set("exp", jian[lvl].exp);
		
	set("unit", "��");
	set("no_give", "���������ˣ�����������ĳ�����");
	set("no_drop", "�벻Ҫ����������");
	set("no_get", "���ֲ��Ǽ����õġ���");
	set("value", 0l);
	set("rubbish", 1);
	set("material", "steel");
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	char szTarget[40];
	char szNum[20];

	if(strcmp(comm, "give") == 0)
	{
		if(! strlen(arg)) return 0;
	
		analyse_string(arg, szTarget, 40);
		analyse_string(szTarget, szNum, 20);

		CContainer * obj = (me->environment())->Present(atol(szTarget));
		if(!obj) return 0;

		if(obj->query("rubbish"))
		{
			char msg[255];
			int i;

			i = random(query("exp")) + 1;
			me->add("combat_exp",i);
			 
			message_vision(snprintf(msg, 255, "$n����$N���˸�ͷ������л��λ%s��", query_respect(me)), me, obj);
			message_vision(snprintf(msg, 255, "$N�����%d���飡", i), me, obj);

			destruct(this);
			return 1;
		}

		return notify_fail("���������ˣ�����������ĳ�����");
	}

	return 0;
}

ITEM_END;