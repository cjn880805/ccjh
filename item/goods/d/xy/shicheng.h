//shicheng.h ʯ��
ITEM_BEGIN(CIshicheng)

virtual void create(int nFlag = 0)		
{
	set_name("ʯ��","shi cheng");
	set("unit", "��");
	set("no_get", "");
	set_weight(1);
};


virtual int do_look(CChar * me)
{
	say("����һ�������������ʯ�ӣ�����Ҳ����ʯ��ĥ�ɣ��ƺ������������Щʲô������", me);
	if(me->query_temp("xy/renwu6_2") && me->query("xy/renwu6"))
	{
		AddMenuItem("����ʯ����", "$9fang $1", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("xy/renwu6_2") && me->query("xy/renwu6"))
	{
		if(!strcmp(comm, "fang")  )
			return do_fang(me, arg);

		if(!strcmp(comm, "nine") )
		{
			return do_fang1(me, 9);
		}
		if(!strcmp(comm, "eight") )
		{
			return do_fang1(me, 8);
		}
		if(!strcmp(comm, "seven") )
		{
			return do_fang1(me, 7);
		}
		if(!strcmp(comm, "six") )
		{
			return do_fang1(me, 6);
		}
		if(!strcmp(comm, "five") )
		{
			return do_fang1(me, 5);
		}
		if(!strcmp(comm, "four") )
		{
			return do_fang1(me, 4);
		}
		if(!strcmp(comm, "three") )
		{
			return do_fang1(me, 3);
		}
		if(!strcmp(comm, "two") )
		{
			return do_fang1(me, 2);
		}
		if(!strcmp(comm, "one") )
		{
			return do_fang1(me, 1);
		}
	}
	return 0;
}

int do_fang1(CChar *me, int num)
{
	char msg[255],str[255];
	CContainer * shikuai;
	shikuai=me->present("shi kuai");
	if(shikuai && shikuai->Query_Amount()>=num)
	{
		CContainer * env=me->environment();
		if(env->query("index"))
		{
			snprintf(msg, 255,"xy/renwu6_3_%d",env->query("index"));
			if(!me->query_temp(msg))
			{
				me->set_temp(msg,num);
				shikuai->set_amount(shikuai->Query_Amount()-num);
				tell_object(me, snprintf(msg, 255,"\n$YEL��ӻ����ͳ�%söʯ���ӣ�����ķ���ʯ���С�",chinese_number(num, str))); 
				tell_object(me,"$YELֻ��ʯ�ӻ���һ����ʯ����ͻȻ����һ��¡¡���������þͻָ���ƽ����\n");
				for(int i=1;i<10;i++)
				{
					snprintf(msg, 255,"xy/renwu6_3_%d",i);
					if(me->query_temp(msg))
						me->add_temp("xy/renwu6_3",1);//��������Ѿ�������ʯ���ӵķ�����Ŀ
				}
				if(me->query_temp("xy/renwu6_3")==9)
				{
					tell_object(me,"$YELƬ��֮����Ȼ����һ����죬����ʯ�Ҷ���֮ҡ����������Լ�У����ƺ�������Զ���о�����ֵ�������\n");
					load_item("shizhu")->move(load_room("��ң�ȷ���֮��"));
				}
				else
					me->delete_temp("xy/renwu6_3");
			}
			else
			{
				tell_object(me,"\n$YEL�㷢��ʯ�����Ѿ��ڷ�����ʯ���ӡ�\n");
			}
		}
		else
		{
			tell_object(me,"\n$YEL�������ף����治֪��������ô����������������񣬾��棡������\n");
		}
	}
	else
	{
		tell_object(me,snprintf(msg, 255,"\n$YEL�����ֵ�����׼���ͳ�%söʯ���ӷ���ʯ���У����˰���ȴ�����ò�����ô�ࡣ\n",chinese_number(num, str)));
	}
	return 1;
}

int do_fang(CChar *me, char * arg)
{
	if(me->query_temp("xy/renwu6_2") && me->query("xy/renwu6"))
	{
		CContainer * shikuai;
		shikuai=me->present("shi kuai");
		if(shikuai)
		{
			if(shikuai->Query_Amount()>=9)
			{
				AddMenuItem("���þ�ö����", "$9nine $1", me);
			}
			if(shikuai->Query_Amount()>=8)
			{
				AddMenuItem("���ð�ö����", "$9eight $1", me);
			}
			if(shikuai->Query_Amount()>=7)
			{
				AddMenuItem("������ö����", "$9seven $1", me);
			}
			if(shikuai->Query_Amount()>=6)
			{
				AddMenuItem("������ö����", "$9six $1", me);
			}
			if(shikuai->Query_Amount()>=5)
			{
				AddMenuItem("������ö����", "$9five $1", me);
			}
			if(shikuai->Query_Amount()>=4)
			{
				AddMenuItem("������ö����", "$9four $1", me);
			}
			if(shikuai->Query_Amount()>=3)
			{
				AddMenuItem("������ö����", "$9three $1", me);
			}
			if(shikuai->Query_Amount()>=2)
			{
				AddMenuItem("���ö�ö����", "$9two $1", me);
			}
			AddMenuItem("����һö����", "$9one $1", me);
			SendMenu(me);
		}
	}
	else
	{
		say("\n$YEL�����ֵ�����׼���ͳ�ʯ���ӷ���ʯ���У����˰���ȴ�����Ҳ������ԷŵĶ�����\n",me);
		SendMenu(me);
	}
	return 1;
}
ITEM_END;




