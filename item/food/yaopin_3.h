FOOD_BEGIN(CIyaopin_4);

void create(int nFlag = 0)
{
	char msg[255];

	static struct{
		char name[20], id[20];
		int type;				//���
		LONG weight;			//����
		LONG val;				//��ֵ	
	}yao[11] = {
		{"��Ҷһ֦","guiyuan dan",1,1200, 4000, },        {"�ϻ�����","huishen gao",2,1500, 4000, },        {"ʯ����", "buqi wan",3,2000, 4000,},
		{"����ӡ","baihua gao",4,2000, 4000, },
		{"����������","huixue gao",5,2000, 6400, },	    {"����","jiegu san",6,	1000, 6400, },        {"�߽�","tianxian yulu",7,3000, 8000, },        {"һҶ","jiuzhuan dan",8,3500, 10000, },
		{"����", "tianxiang gao",9,1000, 10000, },
		{"ʯέ", "dahuan dan",10,	2500, 16000, },
		{"����","gongting mifang",11,1000, 16000, },
	};

	int lvl = random(11);

	if(nFlag) lvl = nFlag - 1;

	set("index", lvl + 1);

		set("type", yao[lvl].type);
		set_weight(yao[lvl].weight);
	if (random(40))
	{
		set_name(yao[lvl].name, yao[lvl].id);
		set("value", yao[lvl].val);
	}
	else
	{
		set("flash",1);
		snprintf(msg,255,"��%s",yao[lvl].name);
		set_name(msg, yao[lvl].id);
		set("value", yao[lvl].val*6);
	}

//		set("eat_msg", "$N����һ֧$n��");

//		set("food_remaining", 1);
//	set_amount(1);
}


int do_use(CChar * me, CContainer * target)
{

//	message_vision("$n����һ֧$N��",this,me);
	int i;
	int n;
	n=query("flash");

	switch (query("type"))
	{
	case 1:
		if (n)
			me->set("eff_hp",me->query("max_hp"));
		me->set("hp",me->query("eff_hp"));
		message_vision("$N������ͻȻ�ֳ�һ����������Ѹ��������ȥ��",me);
		tell_object(me,"��ֻ���û����泩�ޱȣ�");
		break;
	case 2:
		me->add_temp("apply/per",1);
		if (n)
		{
			if(me->query("per")<38)
			{
				me->add("per",1);
				message_vision("$N������ͻȻ�ֳ�һ��쳱����Ѹ��������ȥ��",me);
				tell_object(me,"�����ò����ˣ�");
			}
			else
			{
				message_vision("$N������ͻȻ�ֳ�һ��쳱���þò���������ȥ��",me);
				tell_object(me,"�����òû�а취�������ˣ�");
			}
		}
		else
		{
			message_vision("$N������ͻȻ�ֳ�һ��쳱����Ѹ��������ȥ��",me);
			tell_object(me,"�����ò����ˣ�");
		}
		break;
	case 3:
		i=me->query("mp");
		if (n || i*2<me->query("max_mp")*4 )
			me->add("mp",i);
		message_vision("$N������ͻȻ�ֳ�һ��ɱ������Ѹ��������ȥ��",me);
		tell_object(me,"��ֻ����������ʵ�ޱȣ�");
		break;
	case 4:
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/con",i);
		message_vision("$N������ͻȻ�ֳ�һ���������Ѹ��������ȥ��",me);
		tell_object(me,"�����������ˣ�");
		break;
	case 5:
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/str",i);
		message_vision("$N������ͻȻ�ֳ�һ����������Ѹ��������ȥ��",me);
		tell_object(me,"�����������ˣ�");
		break;
	case 6:
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/int",i);
		message_vision("$N������ͻȻ�ֳ�һ���������Ѹ��������ȥ��",me);
		tell_object(me,"����ǻ�����ˣ�");
		break;
	case 7:
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/dex",i);
		message_vision("$N������ͻȻ�ֳ�һ���������Ѹ��������ȥ��",me);
		tell_object(me,"�����������ˣ�");
		break;
	case 8:
		//i=me->query_skill("parry");
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/parry",i);
		message_vision("$N������ͻȻ�ֳ�һ���������Ѹ��������ȥ��",me);
		tell_object(me,"�����Ч�мܵȼ�����ˣ�");
		break;
	case 9:
		//i=me->query_skill("force");
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/force",i);
		message_vision("$N������ͻȻ�ֳ�һ����������Ѹ��������ȥ��",me);
		tell_object(me,"�����Ч�ڹ��ȼ�����ˣ�");
		break;
	case 10:
		//i=me->query_skill("dodge");
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/dodge",i);
		message_vision("$N������ͻȻ�ֳ�һ����������Ѹ��������ȥ��",me);
		tell_object(me,"�����Ч�Ṧ�ȼ�����ˣ�");
		break;
	case 11:
		i=me->query("eff_hp") / 20;
		if (!n)
			i=i/2;
		me->add("eff_hp",i);
		message_vision("$N������ͻȻ�ֳ�һ��Ѫɫ����Ѹ��������ȥ��",me);
		tell_object(me,"��ģȣ���������ˣ�");
		break;
	}

	me->start_busy(1);

	destruct(this);
    return 1; 
}

int Can_Use()
{
	return 1;
}





FOOD_END;
