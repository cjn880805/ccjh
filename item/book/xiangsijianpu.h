// xiangsijianpu.h ��÷�ؼ�
//Lanwood 2001-02-10


ITEM_BEGIN(CIxiangsijianpu);

virtual void create(int nFlag = 0)
{
	set_name( "��÷�ؼ�");

 	set_weight(200);		

	set("unit", "��");
 	set("long", "һ֦������÷��������ϸϸ�Ķд�����΢�Ƶ��ؼ㡣���������������Я����ʮ��֮�����֮��������΢�е��������¡�");
//	set("value",  1500 );
	set("material", "paper");
	set("skill/name","vivien_sword");	// name of the skill
	set("skill/exp_required",  1000);
	set("skill/jing_cost",   20+random(20));
	set("skill/difficulty", 20 );
//	set("skill/max_skill",  300);
//	set("skill/min_skill", 0l);
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "study") == 0)
	{
		if(me->query("hp") < 50)
		{
			tell_object(me, "��е�ͷ���ۻ���ʲôҲ�����塣");
			return 1;
		}
		if(EQUALSTR(querystr("owner1"),me->id(1)) )
		{
			if(!query("skill/max_skill"))
			{
				if(me->query_skill("vivien_sword",1)<340)
				{
					set("skill/max_skill",me->query_skill("vivien_sword",1)+10);
					set("skill/min_skill",me->query_skill("vivien_sword",1));
				}
				else
				{
					set("skill/max_skill",  350);
					set("skill/min_skill",  340);
				}
			}
			if(me->query_skill("vivien_sword",1)>=this->query("skill/min_skill") && me->query("gumu/jq")==me->query("age") 
				&& me->query_temp("gumu/read"))
			{
				tell_object(me, "����ϸ�⿪�д��������ؼ��Ͼ�������徹Ȼд����һ�־���������");
				me->improve_skill("vivien_sword", random(me->query_skill("literate", 1) / 2 + 1) + 1);
				me->add("hp", -50);
				me->start_busy(2);
			}
			else
				tell_object(me, "����ϸ�⿪�д��������ؼ��Ͼ��������������ʦ���ŵıʼ���");

			if( me->query_skill("vivien_sword",1) >= this->query("skill/max_skill"))
			{
				tell_object(me, "$YEL�㿴�ſ��ţ����в�����������������֮�У����ϵ�ī���ѱ������ˮ������ģ��һƬ��");
				me->delete_temp("gumu/read");
				destruct(this);
				return 1;
			}
		}
		else
		{
			tell_object(me, "$YEL�㿴�ſ��ţ����в�����������������֮�У����ϵ�ī���ѱ������ˮ������ģ��һƬ��");
			destruct(this);
			return 1;
		}
		return 1;
	}

	return 0;
}

ITEM_END;




