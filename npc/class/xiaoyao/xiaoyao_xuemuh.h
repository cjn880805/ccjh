//xiaoyao_xuemuh.c ѦĽ��

//code by Fisho
//date:2000-12-22
//inherit F_MASTER;

NPC_BEGIN(CNxiaoyao_xuemuh);

virtual void create()
{
	set_name("Ѧ����", "xue muhua");
	set("long", "�����Ǻų�ҩ����������ҽ����Ѧ���ӣ���˵����ͨҽ�������������������ɹ��ʲ��ߡ� ");
	set("gender", "����");
	set("title","��ң�ɡ����Ȱ��ѡ�");
	set("nickname","ҩ������");
	set("age", 50);
	set("class", "shaman");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
 	set("icon",old_man1);
	
	set("max_hp", 4500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	set("combat_exp", 150000);
	set("score", 80000);
	
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("unarmed",90);
	set_skill("parry", 90);
	set_skill("lingboweibu",80);
	set_skill("beiming_shengong", 80);
	set_skill("zhemei_shou", 80);
	
	map_skill("unarmed", "zhemei_shou");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "zhemei_shou");
	map_skill("force", "beiming_shengong");
	
	create_family("��ң��", 3, "����");
	
	carry_object("cloth")->wear();
	set("no_talk",1);

}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	say(" �ðɣ��Ҿ��������ˣ��Ժ�Ҫ��Ϊ��ң�ɳ�������");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

static void recover(CContainer * ob,LONG param1,LONG param2)
{
	CChar *me=(CChar *)(ob->environment())->Present(param1);

	if (!me)  return ;

	me->set("eff_hp", me->query("max_hp"));
	me->SendState(me);
	message_vision("��Լ����һ�Ѳ��ʱ�ݣ�Ѧ����������վ�������� ",me);
	message_vision("Ѧ����˵������������Ѿ�ȫ����,���������� ", me);
	return ;
}

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	if(! strlen(ask))
	{
		AddMenuItem("��Ѧ������̹������˵�����", "liaoshang",me);	
		AddMenuItem("��Ѧ������̹��ڽ��������", "jingling",me);

		if(me->query_temp("xy/renwu1_4") && !me->query_temp("xy/renwu1_41"))
		{
			AddMenuItem("��Ѧ������̹��ڶ��˵�����","dushang",me);
		}
		if(me->query_temp("xy/renwu1_5") && !me->query_temp("xy/renwu1_6"))
		{
			AddMenuItem("��֪Ѧ���ӹ��ڽⶾ֮��","jiedu",me);
		}
		if(me->query_temp("xy/renwu1_61") && !me->query_temp("xy/renwu1_62"))
		{
			AddMenuItem("ת��Ѧ���ӹ�����Ϧ���֮��","qixi",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "liaoshang") )
	{
		if (DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
		{
			say( "�㲻�����ɵ��ӣ��Ҳ�����Ϊ�����ˡ� ",me);
			SendMenu(me);
		}
		else if (me->query("eff_hp") == me->query("max_hp"))
		{
			command(snprintf(msg,255,"? %ld",me->object_id() ));     
			say("��û�����κ��˰��� ", me);
			SendMenu(me);
		}
		else
		{
			message_vision("Ѧ����ι$N����һ��ҡͷ��,Ȼ����ϥ���£�˫������$N�ı��ġ� ", me);
			me->start_busy(5);
			remove_call_out(recover);
			call_out(recover,5,me->object_id());
		}
		return 1;
	}
	else if(!strcmp(ask, "jingling") )
	{
		if ( DIFFERSTR(me->querystr("family/family_name"), "��ң��"))
		{
			say("�㲻��������ң�ɵ����ˣ�������Щ��ʲô��",me);
		}
		me->set_temp("xiaoyao/����",1);
		say("ʦ����Ȼ�������ˡ���ң������������֪Ϊ�Σ�ʼ�ղ���������ʹ�����ľ��С�",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "dushang") )
	{
		if (me->query_temp("xy/renwu1_4") && !me->query_temp("xy/renwu1_41"))
		{
			//��ң���� ���Ի�� �ⶾ������
			CContainer * bot = load_item("jieduwan");
			bot->move(me);
			me->set_temp("xy/renwu1_41",1);//�õ���ʯ��¶�ⶾ�Ľⶾ������
			say(snprintf(msg, 255,"ԭ������ô����ѽ��%s����Ϊ����ң���۱����������пš��ⶾ�����衹��%s����ȥ���˰ɣ�",query_respect(me),query_respect(me)),me);
		}
		else
			say("ʲô��",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "jiedu") )
	{
		if (me->query_temp("xy/renwu1_5") && !me->query_temp("xy/renwu1_6"))
		{
			me->set_temp("xy/renwu1_6",1);//��֮Ѧ���ӽ�ȵ���ʯ��¶��������Ϧ���
			say(snprintf(msg, 255,"Ѧ��������ʤ���꣺���벻�������о�Ȼ������ʯʦ�ã�%s��ȥ������Ϣ�����Ҵ�ʦ�ֿ���ˮ�ɡ�",query_respect(me)),me);
		}
		else
			say("ʲô��",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "qixi") )
	{
		if (me->query_temp("xy/renwu1_61") )
		{
			if(!me->query_temp("xy/renwu1_62") )
				me->set_temp("xy/renwu1_62",1);//֪ͨѦ���Ӳμ���Ϧ���
			say("Ѧ������һ�����������˵���ľż��һ�����԰���Ϸ�ģ����ߵߣ��˿�Ҳ��֪���ĸ�ϷԺ���ǻ�������ʦ�ַ�ǧ������Զ��ģ�ֻ֪����һ����˪�����ǵ��˽��á�һʱ����֮�䣬��Ҳ�޷�ͬʱ֪ͨ����",me);
			say(snprintf(msg, 255,"Ѧ������һ���������������ɣ���ȥ������ʦ�֣�����ʦ�ֵܾͰ���%sת���ˣ���",query_respect(me)),me);
		}
		else
			say("ʲô��",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;




