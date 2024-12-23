//renwuyue.h	������
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNHeiMUYa_renwoxing);

virtual void create()
{
	set_name("������","ren wo xing");

	set("title",  "�������ԭ����" );
	set("long", "ֻ����һ�ų��������ף���ɫѩ�ף����ް��Ѫɫ��üĿ����,������ߣ�һͷ�ڷ���������һϮ������");
	set("gender", "����");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",old_man2);
	
	set("hp", 9000);
	set("max_hp", 9000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 400);
	set("combat_exp", 6000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("changquan", 200);
	set_skill("xingxiu_duzhang", 200);
	set_skill("lingxu_bu", 200);
	set_skill("damo_jian", 200);
	set_skill("taiji_jian", 200);
	set_skill("huifeng_jian", 200);
	set_skill("taishan_sword", 200);
	set_skill("hengshan_jian", 200);
	set_skill("hengshan_sword", 200);
	set_skill("huashan_sword", 200);
	set_skill("songshan_sword", 200);

	map_skill("dodge", "lingxu_bu");
	map_skill("force", "kuihua_xinfa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");

	set_inquiry("��������",ask_jiuren);

	carry_object("bluecloth")->wear();
	carry_object("changjian")->wield();
}

static char * ask_jiuren(CNpc * npc , CChar * me)
{
	if(me->query_temp("ry/renwu1_4"))
	{
		npc->say("�����м�����������ʯ������÷ׯ����˵����������������������ʩ���ѽ�����������ĵز�������������ͤ�����������������һ������С�䣬ֻ��ͽ��϶�����������Ȩ���֣����������������в��ٹ������ĳ������ĺ�������", me);
		npc->say("�����������ڽ����Ϲ棬�������������췴�ˡ��ҿ���������Ϊ����ϲ������������һ��ȥɱ�˶��������Ǽ��ˣ�����������̣���", me);
		npc->SendMenu(me);
		me->set_temp("ry/renwu1_5",1);//ѡ���Ƿ����������
	}
	else if(me->query_temp("ry/renwu1_3"))
	{
		npc->say("�����д�Ц��:��������������֪����������������ң�û�뵽���ڽ��졣�����������ɵĻ����������ѿ������õ���������", me);
		npc->say("ֻ������ɫͻȻת�࣬ɲʱ��ʯ����а���ҳ壬��ɳ��ʯ�������޷������۾������æ����˫�ۡ�", me);
		npc->say("�ȵ����Կ���������ʱ��ԭ����ס�����е������Ѿ����һ��һ�Σ������롰�������������������", me);
		npc->SendMenu(me);
		me->set_temp("ry/renwu1_4",1);//�����������
	}
	return "";
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("ry/renwu1_5"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("�õģ���Ը������㣡","yes",me);
			AddMenuItem("����������̫�ðɡ�����","no",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "no") )
		{
			tell_object(me,"������˵������Ȼ�����ҵ����ѣ��Ǿ����ҵĵ��ˣ���������������ϰ�¶�ҵļƻ�����");
			((CUser *)this)->Ready_PK();
			((CUser *)me)->Ready_PK();
			me->kill_ob(this);	
			this->kill_ob(me);
			set("owner",me->object_id());
			me->delete_temp("ry");
			me->del("ry");
		}
		else if(!strcmp(ask, "yes") )
		{
			tell_object(me,"\n$HIR�����й�����Ц�������ã��Ϸ��Ȼû�п����ˣ����������· �ɣ���");
			tell_object(me,"$HIR������ͻȻ��¶��ɫ����������ѽ�����ã��Ϸ��걻������ʯ��֮�½ŵ��Ѳ�̫��⣬�ո�һ����С�İѽ����ˡ���");
			tell_object(me,"$HIR�����е�����С�ֵܣ�ֻ������һ����ȥɱ����������С�İ��������ľ�������ţ�������������ϵ���ľ���������¶�����������ȥ����ȥ����Ů��ӯӯ����֪��������˭�ƹ���ڡ���");
			me->set_temp("ry/renwu2_1",1);//�õ���ľ��ȥ����ӯӯ
			CContainer * obj = load_item("baozi");
			obj->set_name("��ľ��", "heimu ling");
			obj->set_weight(500);
			obj->set("unit", "��");
			obj->set("long", "����һ���ǿ�ݽ��ĺ�ɫľͷ����Լ��ߣ��������л������֣�����ʮ�ֹ��졣");
			obj->set("owner1",me->id(1));
			obj->set("ry/heimu_ling",1);
			obj->move(me);
			tell_object(me,"\n$HIC��õ�����1�ĺ�ľ�\n");
			me->move(load_room("÷ׯ��Ϣ��"));
			SendMenu(me);
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual void die()
{
	if(query("owner"))
	{
		CChar * killer;
		CChar * owner;
		if( (killer = (CChar *)find_object(query_temp("last_damage_from"), 1)) )
		{
			//���owner
			owner = (CChar *)find_object(query_temp("fight/owner"), 1);
			if(owner && owner->query_temp("fight/will_nk") == object_id())
				killer = owner;
			
			tell_object(killer,"\n$HIC������ˡ��ƻ������мƻ��������񣬵õ�����888�㡣\n");
			killer->add("combat_exp",888);
			killer->delete_temp("no_fei");
			killer->UpdateMe();
			killer->move(load_room("÷ׯ��Ϣ��"));
		}
	}
	CNpc::die();
}
NPC_END;
