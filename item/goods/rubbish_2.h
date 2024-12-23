//rubbish_2.h
//����
//Teapot 2001-02-03

ITEM_BEGIN(CIrubbish_2);

virtual void create(int nFlag = 0)	
{
	static struct{
		char name[20];
		char id[20];
		LONG weight;			//����
		int  exp;				//��������
	} jian[8] = {
		{"��ȴ�ĺ���С����", "xiaolong bao",12000,50,},
		{"���ƵĲ���", "sui boli",13000,60,},
		{"���ϵķɻ�Ʊ", "feijipiao",  8000,70,},
		{"�ս��ĵعϱ�", "diguabing", 10000,100,},
		{"��������", "sui sancai", 20000,120,},
		{"���ӿ�", "guazi ke", 5000,140,},
		{"�ϵ���һ��ʮ����", "shici lan", 12200,150,},
		{"�̻���CD", "kuai cd", 14200,200,},
	};

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