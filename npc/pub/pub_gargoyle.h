// pub_gargoyle.h
//code by Fisho
//date : 2000-12-13
/*
string *death_msg = {
	  "���޳�˵����ι�������ģ����ʲô���֣�"  ,
	  "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�"  ,
	  "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������"  ,
	  "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�"  ,
	  "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�"
	  "һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣"  ,
};
*/

NPC_BEGIN(CNpub_gargoyle);

virtual void create()
{
	set_name("���޳�", "gargoyle");

	set("icon", masked_man);
	set("long","���޳�������������ͷ�����㣬��ڵ����Ͽ������κ�ϲŭ���֡�");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("age", 217);
	set("combat_exp", 20000);
	set("max_hp", 2700);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 20);

//	set_chat_msg("���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�");
//	set_chat_msg("���޳��ѳ�������ͷ��������������������Լ��ֺ��ֳ�����ָ��");
}

NPC_END;
/*
virtual void init(CChar *me)
{
	CNpc::init(me);
	if( !previous_object()
	||	!userp(previous_object()) )
		return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(CChar * ob, int stage)
{
	int i;
	CChar * inv, mailbox;

	if( !ob || !present(ob) ) return;

	if( !ob->is_ghost() ) {
		say(" ι��������������ʲô��");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

	inv = all_inventory(ob);
	for (i = 0; i < sizeof(inv); i++)
		DROP_CMD->do_drop(ob, inv[i]);
	
	mailbox = load_item("/clone/misc/mailbox");
	mailbox->move(ob);
	ob->move(REVIVE_ROOM);
	message("vision",
		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������"
		"�ܾ��ˣ�ֻ����һֱû������", ob->environment(), ob);
}

*/