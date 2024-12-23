//ssword.h ��������
//coded by Teapot
//data: 2001-03-07

//�޸ģ�
//����װ��ж����������
//���ӹ۲죬�ɲ鿴��������
//Lanwood 2001-03-17

int valid_string(const char * msg);

EQUIP_BEGIN(CIssword);

void create(int nFlag = 0)	
{
	int i;
	i=query("is_left");

	if(_M.undefinedp("name"))
		set_name("����", "weapon");

	if (i)
		set("wield_position", WIELD_LEFT_HAND);
	else
		set("wield_position", WIELD_RIGHT_HAND);
	
	if(_M.undefinedp("skill_type"))
		set("skill_type", "sword");	

	set_weight(10000);	
	
	set("unit", "��");
	set("material", "sapphine");

	if(_M.undefinedp("wield_msg"))
		set("wield_msg", "$N����һ��$n�������С�");
	if(_M.undefinedp("unwield_msg"))
		set("unwield_msg", "$N�����е�$n�������");

	//��������Ƿ��Ѿ�����
	if(DIFFERSTR(name(1), querystr("staticname")) )
	{
		del("apply");
	}
	else
	{
		if (!i)
			set("apply/damage", 20+query("cumpower"));
		else
			set("apply/damage", (20+query("cumpower"))/2 );
	}

	//����Ӳ��
	set("rigidity", 10 + query("cumpower") / 3);

	set("value", 1);
	set("no_sell",1);
	set("no_drop", 1);
	set("teapot/brand",1);
	set("item_make",1);

	set("no_clean_up", 1);	
}

virtual int Can_Equip(CChar * me)
{
	if((! querystr("owner")[0] || EQUALSTR(querystr("owner"), me->querystr("id")) || wizardp(me))
		&& EQUALSTR(name(1), querystr("staticname")) )
		return 1;
	return 0;
};

//����һ���ƶ���������ϵ�ʱ�����
void init()
{
	if(userp(environment()))
	{
		CChar * me = (CChar *)environment();

		if(! querystr("owner")[0] || EQUALSTR(querystr("owner"), me->querystr("id")) )
		{
			if(!me->query_temp("����"))
			{
				set("owner", me->querystr("id"));	//��������
				set_temp("����",1);
				me->set("teapot/referent", object_id());
				me->set_temp("����",1);
				if(query("cumpower")>me->query("teapot/cumpower"))
				{
					set("cumpower",me->query("teapot/cumpower"));
				}
				if(query("cumpower")<me->query("teapot/cumpower"))
				{
					me->set("teapot/cumpower",query("cumpower"));
				}
			}
			else
			{
				if(!query_temp("����"))
					destruct(this);
			}
		}
	}
}

int do_look(CChar * me)
{
	char msg[255];

	CItem::do_look(me);
	say(snprintf(msg, 255, "%s��ǰ�ۼ�������%ld / %ld", name(), query("cumulative"), query("cumpower")), me);
	AddMenuItem("����װ������", "$2wieldmsg $1 $2", me);
	AddMenuItem("����ж������", "$2unwieldmsg $1 $2", me);
	SendMenu(me);
	return 1;
}

LONG Query(int nAttr)
{
	if(nAttr == CAN_SAVE)
		return 1;
	return CEquip::Query(nAttr);

}

int check_msg(char * arg)
{
	char * ptr = NULL;

	ptr = strstr(arg, "$N");
	if(! ptr || ptr - arg > 4)
		return 0;

	if(! strstr(arg, "$n"))
		return 0;

	return 1;
}

int do_wieldmsg(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 255)
		return notify_fail("���ü����˵��������");

	if(! valid_string(arg) )
		return 0;

	//�������Ƿ�Ϸ�
	if(! check_msg(arg))
		return notify_fail("�����������$N�����Լ���$n������������$NҪ����ǰ��");

	set("wield_msg", arg);
	tell_object(me, "OK.");

	Save();
	return 1;
}

int do_unwieldmsg(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 255)
		return notify_fail("���ü����˵��������");

	if(! valid_string(arg) )
		return 0;

	if(! check_msg(arg))
		return notify_fail("�����������$N�����Լ���$n������������$NҪ����ǰ��");

	set("unwield_msg", arg);
	tell_object(me, "OK.");

	Save();
	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "wieldmsg") == 0)
	{
		return do_wieldmsg(me, arg);
	}
	else if(strcmp(comm, "unwieldmsg") == 0)
	{
		return do_unwieldmsg(me, arg);
	}
	else if(strcmp(comm, "specialmake") == 0)
	{
		if (!query("is_left"))
			set("is_left",1);
		else
			del("is_left");
		tell_object(me,"Ok.");
		return 1;
	}

	return CEquip::handle_action(comm, me, arg);
}


int query_autoload()
{
	return 1;
}

const char * hit_ob(CChar *me, CChar *victim, LONG damage)
{
	int i = query("cumpower");
	
	if (! i)	i=1;

//	sml="$w֮�ϵ�ɱ����Ũ����һ˿����";
	add("cumulative",1);	//�ۻ�ά�֡����������ҳɳ���
//	me->add("teapot/cumulative",1);	��Ҳ���¼�ۻ�ά�֡�

	if (query("cumulative") >= i*i)
	{
		set("cumulative",0l);
		me->add("teapot/cumpower",1);
		add("cumpower",1);

		if(query("cumpower")>me->query("teapot/cumpower"))
		{
			set("cumpower",me->query("teapot/cumpower"));
		}
		if(query("cumpower")<me->query("teapot/cumpower"))
		{
			me->set("teapot/cumpower",query("cumpower"));
		}

		if (!query("is_left"))
		{
			add("apply/damage",1);
			me->add_temp("apply/damage",1); // ��֤�������ж�����������֡�
		}
		else
		{
			i=query("cumpower");
			if (i%2==0)
			{
				add("apply/damage",1);
				me->add_temp("apply/damage",1); // ��֤�������ж�����������֡�
			}

		}

		output_error("%s������%s������%ld��", me->name(1), name(1), i);

		return "$HIR$wͻȻɱ����ʢ��Ѫɫ�������Ե��쳣�ɲ���";
	}

	return 0;
}

EQUIP_END;
