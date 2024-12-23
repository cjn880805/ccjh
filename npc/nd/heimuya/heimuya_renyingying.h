//renyingying.h	��ӯӯ
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_renyingying);

virtual void create()
{
	set_name("ӯӯ","ren yingying");

	set("title",  "����ʥ��" );
	set("long", "����ķ��飬��̬���ţ��俴��ȥ���ýӽ�����������������ʧΪһ���˵����ˡ�");
	set("gender", "Ů��");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);	//��������������
	set("str", 16);
	set("per", 27);
	set("int", 27);
	set("con", 17);
	set("dex", 18);
 	set("icon",young_woman2);
	
	set("hp", 2000);
	set("max_hp", 2000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 50);
	set("combat_exp", 1000000);
	set("score", 100000);

	set_skill("literate", 200);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("unarmed", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("changquan", 120);
	set_skill("xingxiu_duzhang", 120);
	set_skill("lingxu_bu", 120);
	set_skill("damo_jian", 120);
	set_skill("taiji_jian", 120);
	set_skill("huifeng_jian", 120);
	set_skill("taishan_sword", 120);
	set_skill("hengshan_jian", 120);
	set_skill("hengshan_sword", 120);
	set_skill("huashan_sword", 120);
	set_skill("songshan_sword", 120);

	map_skill("dodge", "lingxu_bu");
	map_skill("force", "xingxiu_duzhang");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");
	
	set("chat_chance", 10);

	set_inquiry("����", "�㿴���ҵĳ����ô�����Ҵ�һ���Ÿ�����ô��");
	set_inquiry("�Ϸ��", "�����嶾�̵Ľ������ҵĺ����ѡ�");
	set_inquiry("������", "�ҵ�����һ��û������һ��Ҫ�ҵ�����");
	set_inquiry("��������", "����������Һܺã����һֱû��������");
	set_inquiry("Ц��������", "����һ�׺ܶ��˵����ӣ�Ҫ�ǳ���������Ϳ��Ժ�����������ˡ�");
//	set_inquiry("����", ask_songxin);
//	set_inquiry("����", ask_qupu);

	carry_object("changjian")->wield();
//	carry_object("letter")->wield();

	create_family("�������",2,"����");
	set("no_huan",1);
}

virtual char * chat_msg()		//NPC�Զ�����
{
	switch(random(3))
	{
	case 0:
		return 	"ӯӯüͷֱ�壬̾������֪�������������,�Ƿ��ֺ���С������һ��......";
	case 1:
		return 	"ӯӯ����ϣ���Ŀ�������������ܰ�������Ը�������̫лл����.............";
	case 2:
		return 	"ӯӯ������������ȥû������Ҳ��֪�Ϸ�˼�û�����������漱������.......";
	}

	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("ry/renwu2_1") && !me->query_temp("ry/renwu2_2"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("���ں�ľ��������ڵ�����","rukou",me);
		}
		else if(!strcmp(ask, "rukou") )
		{
			say("ӯӯ���������������չ���ľ��ǳ��ɣ���������˼�ش�������⡣��������һ���־꣬��������ҽ������ɣ���",me);
			CContainer * obj = load_item("baozi");
			obj->set_name("�־�", "shou juan");
			obj->set_weight(500);
			obj->set("long", "����һ��Ů���õ��־ꡣ");
			obj->set("owner1",me->id(1));
			obj->set("ry/shoujuan",1);
			obj->move(me);
			me->set_temp("ry/renwu2_2",1);//���������������ɵ�����
			tell_object(me,"\n$HIC��õ�����1���־ꡣ\n");
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	if(me->query_temp("ry/renwu2_3") && !me->query_temp("ry/renwu3_1"))
	{
		if (obj->query("ry/xin") &&  EQUALSTR(obj->querystr("owner1"), me->id(1)))
		{
			say( "ӯӯ���˵�˵��:����������˵һ��ʱ��ͻ������ң�����̫���ˣ����ˣ���ղ�ѯ�ʺ�ľ��������ô�����������ˣ������������Ϲٷ縺����Ѻ�ľ������Ϳ�����ȥ�ˣ���", me);
			me->set_temp("ry/renwu3_1",1);//������Ÿ�ӯӯ������
			destruct(obj);
			SendMenu(me);
			return 1;
		}
	}
	return 0;
}
/*
string inquiry_linghuchong()
{
	object me=this_player();
	object obn;
	
	message_vision("ȥ���ϻ�ɽһȥ����������,�����������Ұ�......\n"
		, me );
	if(query_temp("letter")==0)
	{  message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ���
	�����ȥѰ���ˣ�Ҳ��֪����ô���ˡ�\n",me);
	return "";
	}
	message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"����������
		��, ��Ҫ���ҵ������塻���Ͱ��Ž��������������׵ġ�\n" , me);
		obn=new("/d/heimuya/npc/obj/letter");
	obn->move(me);
	set_temp("letter",0);
	
	return ("����ŷ��㽻������塣\n");
}
*/
NPC_END;