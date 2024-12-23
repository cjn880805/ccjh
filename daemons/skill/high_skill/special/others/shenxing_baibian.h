// shenxing_baibian.c 神行百变
//by sound
//2001-07-21

SKILL_BEGIN(CSshenxing_baibian);

virtual void create()
{
	set_name( "神行百变");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={
		{"$n一式「行云流水」，身不倾，脚不移，身体如行云流水般直滑出丈余。",},
		{"$n一式「潜音夜行」，忽然一弯腰，全身贴地而行，顿时闪过了$N的凌厉攻势。",},
		{"$n一式「移步换形」，足不动，手不抬，一转眼间便绕到了$N的身后。",},
		{"$n一式「分身化影」，一转身间，四面八方飘动着无数个$n的身影，令$N手足无措。",},
		{"$n一式「凌波微步」，左踏巽，右转乾，身行一晃，便到几丈远的地方。",},
		{"$n一式「更上层楼」，身在空中，左脚在右足上一点，从$N头顶腾空而过。",},
		{"$n一式「仙子出水」，长袖一拂，全身化为一道白影，幽幽地从$N头顶飘落。",},
		{"$n一式「峰回路转」，身体如陀螺般急转，登时一股气流涌出，令$N难以动弹。",},
		{"$n一式「临行秋波」，身行倏的从$N的眼前直绕到身后，$N瞪大了两眼，不明所以。",},
		{"$n一式「浪子回头」，身行倏的从$N的眼前飘过，长发一甩，潇洒之极。",},
	};
	
	return dodge_msg[random(10)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

SKILL_END;

