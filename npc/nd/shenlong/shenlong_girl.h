// girl.c
//code by sound
//2001-07-12

NPC_BEGIN(CNshenlong_girl);

virtual void create()
{
	set_name("����Ů����", "young girl");
	set("icon",young_woman4);
	set("title", "�����̳���ʹ���µ���");
	set("long", "����һ��������Ů���ӣ�һϮ���£�������Ϊ�ɰ���");
	
	set("gender", "Ů��");
	set("attitude", "peaceful");
	
	set("age", 10+random(10));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_hp", 200);
	set("hp", 200);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 5+random(5));
	set("combat_exp", 20000+random(10000));
	
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 60);
	set_skill("shedao_qigong", 30);
	map_skill("sword","shedao_qigong");
	set("chat_chance", 3);
	
	carry_object("xionghuang")->wield();
	carry_object("duanjian")->wield();
	carry_object("cloth")->wear();

}

virtual char * chat_msg()						//NPC�Զ�����
{
	switch(random(5))
	{
	case 0:
		return 	"������Ӻ�Ȼ�����е�:������ѵ,ʱ������,�����˵�,���²��ɣ���";
	case 1:
		return 	"������Ӻ�Ȼ�����е�:��־���Ŀɳɳ�,���������ޱ��ף�";
	case 2:
		return 	"������Ӻ�Ȼ�����е�:��������������,���������ǰ˷���";
	case 3:
		return 	"������Ӻ�Ȼ�����е�:�˷����˳�Ӣ��,������ͬ���¹⣡";
	case 4:
		return 	"������������е�:���������ɸ�,�������룡";
	}
	
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	
	if(me->query("wei/renwu1") && me->query_temp("wei/renwu4_4") && !me->query_temp("wei/renwu4_5") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("����������ޭ��","she",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "she") )
		{
			CContainer * xionghuang=me->present("xionghuang");
			
			if(xionghuang)
			{
				tell_object(me,"����Ů���Ӹ����㣺��С�ģ�ޭ�����Ͳ��̣��涾�ޱȡ���");
				tell_object(me,"����Ů���Ӹ�������1��С����");
				tell_object(me,"����Ů���ӴҴ��뿪�ˡ�");
				me->set_temp("wei/renwu4_5",1);
				load_npc("baishu")->move(me);
				destruct(this);
			}
			else
			{
				say("����Ů���Ӵ���������֪������ļһ���������ȥ����",me);
				SendMenu(me);
			}
		}
		return 1;
	}
	
	return CNpc::do_talk(me,ask);
}

NPC_END;