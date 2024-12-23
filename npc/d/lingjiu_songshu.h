//lingjiu_songshu.c
//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_songshu);

virtual void create()
{
	set_name("À… Û", "song shu" );
	set("race", "“∞ ﬁ");
	set("age", 2);
	set("long", "“ª÷ªø…∞ÆµƒÀ… Û°£");
	set("attitude", "peaceful");
	
	set("str", 15);
	set("cor", 16);
	
 	set("combat_exp", 300);
	
	set_temp("apply/attack", 5);
	set_temp("apply/damage", 3);
	set_temp("apply/defence",5);
	set_temp("apply/armor",3);
	
}
NPC_END;